#!/usr/bin/python3
class BaseGarage:
    def __init__(self, num_parking_spots, num_companies):
        self.num_parking_spots = num_parking_spots
        self.num_companies = num_companies
        self.company_spots_limit = [0 for _ in range(num_companies)]

    def set_num_allocated_spots(self, company_index, amount):
        self.company_spots_limit[company_index] = amount
    
    def is_parked(self, plate):
        return self.is_in_parking_spot(plate) or self.is_in_not_parking_spot(plate)
    
    def park(self, plate):
        if self.num_free_parking_spots() > 0:
            self.park_parking_spot(plate)
            company = self.get_company_for_plate(plate)
            result = self.num_free_parking_spots_company(company) <= 0
            self.park_for_company(company, plate)
            return result
        return self.park_not_parking_spot(plate)


    def unpark(self, plate):
        if self.is_in_not_parking_spot(plate):
            self.unpark_not_parking_spot(plate)
            return False
        self.unpark_parking_spot(plate)
        company = self.get_company_for_plate(plate)
        self.unpark_for_company(company, plate)
        return False

    def process(self, plate):
        if self.is_parked(plate):
            return self.unpark(plate)
        return self.park(plate)


class Garage(BaseGarage):
    def __init__(self, num_parking_spots, num_companies):
        super().__init__(num_parking_spots, num_companies)
        self.parked = set()
        self.plate_to_company = {}
        self.parked_company = [set() for _ in range(num_companies)]

    def register_plate_to_company(self, company_index, plate):
        self.plate_to_company[plate] = company_index

    def get_company_for_plate(self, plate):
        return self.plate_to_company.get(plate, None)
    
    def is_in_parking_spot(self, plate):
        return plate in self.parked

    def is_in_not_parking_spot(self, plate):
        return False

    def num_free_parking_spots(self):
        return 1
    
    def num_free_parking_spots_company(self, company):
        if company is None:
            return 0
        return self.company_spots_limit[company] - len(self.parked_company[company])
    
    def park_for_company(self, company, plate):
        if company is None:
            return
        self.parked_company[company].add(plate)

    def park_not_parking_spot(self, plate):
        return False

    def park_parking_spot(self, plate):
        self.parked.add(plate)
        return False

    def unpark_for_company(self, company, plate):
        if company is None:
            return
        self.parked_company[company].remove(plate)

    def unpark_not_parking_spot(self, plate):
        return False

    def unpark_parking_spot(self, plate):
        self.parked.remove(plate)
        return False


if __name__ == "__main__":
    n, k = map(int, input().split())

    garage = Garage(n, k)

    for i in range(garage.num_companies):
        num_allocated_spots, num_registered_plates = map(int, input().split())
        garage.set_num_allocated_spots(i, num_allocated_spots)
        for _ in range(num_registered_plates):
            plate = input()
            garage.register_plate_to_company(i, plate)

    result = set()
    num_queries = int(input())

    for _ in range(num_queries):
        plate = input()
        if garage.process(plate):
            result.add(plate)

    print(len(result))
    for plate in sorted(result):
        print(plate)
