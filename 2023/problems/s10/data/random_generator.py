#!/usr/bin/python3
import sys
import random

from sol import Garage
from string import ascii_uppercase, digits

PLATECHARS = ascii_uppercase + digits

random.seed(int(sys.argv[-1]))

min_n = eval(sys.argv[1])
max_n = eval(sys.argv[2])
min_k = eval(sys.argv[3])
max_k = eval(sys.argv[4])
min_m = eval(sys.argv[5])
max_m = eval(sys.argv[6])

good_companies = sys.argv[7] == "good_companies"
good_parkers = sys.argv[8] == "good_parkers"

while True:
    m = random.randint(min_m, max_m)

    if not good_parkers:
        max_n = min(m-1, max_n)
        min_n = min(m-1, min_n)
    
    n = random.randint(min_n, max_n)
    max_k = min(n, max_k)
    min_k = min(n, min_k)
    k = random.randint(min_k, max_k)

    def gen_distribution(n, k, minval=1):
        if minval*k == n:
            return [minval] * k
        L = [random.randint(minval, max(minval, n-k+10)) for _ in range(k)]
        S = sum(L)
        while S > n:
            for i in range(k):
                L[i] = max(minval, L[i] - random.randint(0, max(1, L[i]//10)))
            S = sum(L)
        return L

    def gen_plate(min_length=2, max_length=6):
        n = random.randint(min_length, max_length)
        return ''.join(random.choice(PLATECHARS) for _ in range(n))

    PLATE_LIM = 4*10**5
    plate_count = min(m+2*n, PLATE_LIM - m)

    while True:
        company_distribution = gen_distribution(n, k)
        assert not any(x==0 for x in company_distribution)
        plate_distribution = gen_distribution(plate_count, k+1, 2)
        max_ind = max(range(0, k+1), key=plate_distribution.__getitem__)
        plate_distribution[-1], plate_distribution[max_ind] = plate_distribution[max_ind], plate_distribution[-1]
        for i in range(k):
            take = plate_distribution[i]//5
            plate_distribution[i] -= take
            plate_distribution[k] += take
            company_distribution[i] = min(company_distribution[i], plate_distribution[i]-1)
        if sum(company_distribution) + plate_distribution[-1] > n and sum(plate_distribution) > n:
            break

    plate_count = sum(plate_distribution)
    plates = set()
    while len(plates) < plate_count:
        plates.add(gen_plate(2, 5))
    plates = list(plates)

    garage = Garage(n, k)
    company_plates = [[] for _ in range(k+1)]

    plate_index = 0

    for i in range(k):
        garage.set_num_allocated_spots(i, company_distribution[i])
        for _ in range(plate_distribution[i]):
            garage.register_plate_to_company(i, plates[plate_index])
            company_plates[i].append(plates[plate_index])
            plate_index += 1

    while plate_index < len(plates):
        company_plates[k].append(plates[plate_index])
        plate_index += 1
    

    fill_company = None
    if not good_companies:
        fill_company = random.randint(0, k-1)
    for i in range(k+1):
        random.shuffle(company_plates[i])
        company_plates[i] = set(company_plates[i])
    non_empty_companies = list(range(0, k+1))

    OK = 0
    UNPARK = 1
    NOT_PARKING_SPOT = 2
    BREAKING_LIMIT = 4

    def get_type(plate):
        res = OK
        company = garage.get_company_for_plate(plate)
        if garage.is_parked(plate):
            return UNPARK | res
        if garage.num_free_parking_spots() == 0:
            return NOT_PARKING_SPOT | res
        if company is not None and garage.num_free_parking_spots_company(company) == 0:
            if garage.num_free_parking_spots() > 0:
                return BREAKING_LIMIT | res
            return NOT_PARKING_SPOT | res
        return res

    output = []

    banned_types = []
    if good_parkers:
        banned_types.append(NOT_PARKING_SPOT)
    else:
        banned_types.append(UNPARK)
    if good_companies:
        banned_types.append(BREAKING_LIMIT)
    else:
        banned_types.append(UNPARK)

    check_types = {NOT_PARKING_SPOT, BREAKING_LIMIT} - set(banned_types)
    type_counts = {OK: 0, UNPARK: 0, NOT_PARKING_SPOT: 0, BREAKING_LIMIT: 0}
    plate_index = 0

    """
    print(n, k, m)
    print(plate_distribution)
    print(company_distribution)
    print("banned:", banned_types)
    print("check:", check_types)
    """
    for j in range(m):
        while True:
            if UNPARK not in banned_types:
                plate = random.choice(plates)
            else:
                company_choice = fill_company if fill_company is not None else random.choice(non_empty_companies)
                plate = company_plates[company_choice].pop()
                #print(company_choice, plate)
                #print(type_counts)
            park_type = get_type(plate)
            #print(plate, park_type, garage.get_company_for_plate(plate), garage.num_free_parking_spots())
            condition = not good_companies and type_counts[BREAKING_LIMIT] == 0 and garage.get_company_for_plate(plate) is None
            if not condition and park_type not in banned_types:
                type_counts[park_type] += 1
                if UNPARK in banned_types:
                    if not good_companies and type_counts[BREAKING_LIMIT] == 1 and park_type == BREAKING_LIMIT:
                        fill_company = None
                    if (good_parkers or type_counts[NOT_PARKING_SPOT] > 0) and (good_companies or type_counts[BREAKING_LIMIT] > 0):
                        banned_types.remove(UNPARK)
                break
            elif UNPARK in banned_types:
                company_plates[company_choice].add(plate)


        output.append(plate)
        garage.process(plate)
        #print("Added ", plate, [garage.num_free_parking_spots_company(i) for i in range(k)])
        if UNPARK in banned_types:
            if len(company_plates[company_choice]) == 0 or (good_companies and company_choice < k and garage.num_free_parking_spots_company(company_choice) == 0):
                non_empty_companies.remove(company_choice)
    
    if not good_parkers and type_counts[NOT_PARKING_SPOT] == 0:
        continue
    if not good_companies and type_counts[BREAKING_LIMIT] == 0:
        continue

    plate_index = 0
    print("{} {}".format(n, k))
    for i in range(k):
        print("{} {}".format(company_distribution[i], plate_distribution[i]))
        for _ in range(plate_distribution[i]):
            print(plates[plate_index])
            plate_index += 1
    print(m)
    for plate in output:
        print(plate)
    break
