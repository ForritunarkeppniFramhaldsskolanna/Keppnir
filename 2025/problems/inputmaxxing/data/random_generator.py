#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])

n = random.randint(min_n, max_n)

print(n)

for _ in range(n):
    p = random.uniform(1, 9)
    x = int(10**p)
    x = max(x, 10)
    x = min(x, 10**9)
    print(x)
