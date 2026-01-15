#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
max_t = eval(sys.argv[2])
max_sm = eval(sys.argv[3])

n = random.choice([max_n, random.randint(max_n // 2, max_n)])
n = max(n, 1)
n = min(n, 10**5)

T = random.randint(1, max_t)

print(n, T)

w = []

if max_sm >= n * 10**9:
    w = [random.randint(0, 10**9) for _ in range(n)]
else:
    w = [0 for _ in range(n)]
    sm = random.randint(0, max_sm)
    for _ in range(sm):
        i = random.randint(0, n - 1)
        w[i] += 1

print(" ".join([str(x) for x in w]))
