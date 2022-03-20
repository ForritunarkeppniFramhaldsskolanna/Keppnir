#!/usr/bin/env python3

import sys
import random


def name_gen():
    first_part = [
        "Gunnars",
        "Fljots",
        "Gvendar",
        "Ha",
        "Peturs",
        "Lang",
        "Margretar",
        "Hlidar",
        "Berg",
        "Bolla",
        "Ara",
        "Arnars",
        "Fannars",
        "Ulfars",
        "Oxna",
        "Stefans",
        "Ragnars",
    ]
    second_part = [
        "fljots",
        "grjots",
        "holts",
        "dals",
        "skala",
        "tapa",
        "stada",
        "djupa",
        "lons",
        "vogs",
    ]

    # print("maximum combinations: %s" % (len(first_part) * len(second_part)))
    random_first = random.choice(first_part)
    random_second = random.choice(second_part)

    return random_first + random_second + "heidi"


def gen_n_names(name_count):
    names = set()
    while len(names) < name_count:
        random_name = name_gen()
        if random_name not in names:
            names.add(random_name)
    return names


random.seed(int(sys.argv[-1]))

max_v = eval(sys.argv[1])
max_n = eval(sys.argv[2])
max_k = eval(sys.argv[3])

v = random.randint(0, max_v)
print(v)
n = random.randint(1, max_n)
print(n)

random_names = list(gen_n_names(n))

assert len(random_names) == n

for i in range(n):
    k_i = random.randint(0, max_k)
    print(random_names[i], k_i)
