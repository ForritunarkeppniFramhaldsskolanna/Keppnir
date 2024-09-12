#!/usr/bin/python3
import math
import random
import string
import sys

random.seed(int(sys.argv[-1]))

min_n = eval(sys.argv[1])
max_n = eval(sys.argv[2])
min_m = eval(sys.argv[3])
max_m = eval(sys.argv[4])
min_k = eval(sys.argv[5])
max_k = eval(sys.argv[6])
min_popularity = eval(sys.argv[7])
max_popularity = eval(sys.argv[8])
min_distinct = eval(sys.argv[9])
max_distinct = eval(sys.argv[10])

n = random.randint(min_n, max_n)
distinct = random.randint(min_distinct, max_distinct)


charset = string.ascii_letters + string.digits

def generate_name():
    return "".join([random.choice(charset) for _ in range(random.randint(1, 4))])

def generate_popularity():
    return random.randint(min_popularity, max_popularity)

def generate_unique(func, already_existing):
    while (val := func()) in already_existing:
        pass
    return val


if max_m > 0 and max_k > 0 and max_distinct > 1:
    for _ in range(1000):
        names = set()
        popularities = set()

        for _ in range(n):
            name = generate_unique(generate_name, names)
            names.add(name)

        for _ in range(distinct):
            popularity = generate_unique(generate_popularity, popularities)
            popularities.add(popularity)

        names = list(names)
        random.shuffle(names)

        popularities = list(popularities)
        for _ in range(distinct, n):
            index = random.randint(0, distinct - 1)
            popularities.append(popularities[index])

        def solve(n, m, k, pop):
            cards = 0
            cur_cost = sum(pop) * m
            bst_sum, bst_card = cur_cost, 0

            for i in range(len(pop)):
                while cards < pop[i]:
                    cur_cost += k
                    cur_cost -= (len(pop) - i) * m
                    cards += 1
                    if bst_sum > cur_cost:
                        bst_sum = cur_cost
                        bst_card = cards
            return bst_card, bst_sum

        max_pop = max(popularities)
        sum_pop = sum(popularities)
        sorted_pop = sorted(popularities)
        min_k = max(min_k, max_pop)
        k = random.randint(min_k, max_k)
        temp_max_m = max(min_m, min(max_m, max_pop * k // sum_pop))
        temp_min_m = min(temp_max_m, max(min_m, k // max_pop))
        m = random.randint(temp_min_m, temp_max_m)
        cards, sm = solve(n, m, k, sorted_pop)
        if cards == 0:
            max_k = min_k + int((max_k - min_k) * 0.95)
        elif cards == max_pop:
            min_k = min_k + int((max_k - min_k) * 0.05)
        if 0 < cards < max_pop:
            break

else:
    names = set()
    popularities = set()

    for _ in range(n):
        name = generate_unique(generate_name, names)
        names.add(name)

    for _ in range(distinct):
        popularity = generate_unique(generate_popularity, popularities)
        popularities.add(popularity)

    names = list(names)
    random.shuffle(names)
    popularities = list(popularities)

    for _ in range(distinct, n):
        index = random.randint(0, distinct - 1)
        popularities.append(popularities[index])
    m = random.randint(min_m, max_m)
    k = random.randint(min_k, max_k)

print(f"{n} {m} {k}")
for name, popularity in zip(names, popularities):
    print(f"{name} {popularity}")
