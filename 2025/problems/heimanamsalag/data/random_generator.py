#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

max_n = int(sys.argv[1])
ab_eq = int(sys.argv[2])
rng = eval(sys.argv[3])
max_t = 10**9
if sys.argv[4] == "small":
    max_t = 100

n = random.choice([max_n, random.randint(max(1, max_n // 2), max_n)])
print(n)

for _ in range(n):
    a = random.randint(0, rng)
    b = random.randint(0, rng)
    t = random.randint(0, max_t)
    if a > b:
        a, b = b, a
    if ab_eq:
        b = a
    print(a, b, t)
