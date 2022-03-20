#!/usr/bin/env python3

import sys
import random
import string

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
recycling_percentage = eval(sys.argv[2])
threshold = eval(sys.argv[3])


# n = random.randint(1, max_n)
n = max_n


city_name = (
    random.choice(string.ascii_uppercase)
    + "".join([random.choice(string.ascii_lowercase) for _ in range(n)])
    + "burg"
)
print(city_name)
print("{:.2f}".format(recycling_percentage))
print(n)

for i in range(n):
    random_sample = random.uniform(0, 1)
    if random_sample > threshold:
        print("plast")
    else:
        print("ekki plast")
