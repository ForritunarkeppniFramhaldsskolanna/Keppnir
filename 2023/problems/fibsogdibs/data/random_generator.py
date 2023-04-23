#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])

a = random.randint(1, 10**5)
b = random.randint(a, 10**5)

print(a, b)
print(random.randint(min_n, max_n))
