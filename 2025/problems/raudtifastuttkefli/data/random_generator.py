#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "rand":
    max_n = int(sys.argv[2])
    max_k = int(sys.argv[3])
    n = random.choice([max_n, random.randint(max_n // 2, max_n)])
    n = max(n, 1)
    k = random.randint(0, max_k)
    print(n, k)
    sm = random.choice([10**5, random.randint(n, 10**5)])
    lens = [0 for _ in range(n)]
    for _ in range(sm):
        ind = random.randint(0, n - 1)
        lens[ind] += 1
    dops = [random.randint(0, 10**9) for _ in range(n)]
    for i in range(n):
        print(lens[i], dops[i])
    T = random.randint(0, sum(lens))
    if n == 1:
        T = random.randint(0, sum(lens) * 2)
    print(T)
