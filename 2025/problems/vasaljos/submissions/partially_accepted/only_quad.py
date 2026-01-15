#!/usr/bin/python3
from itertools import combinations

n = int(input())
for i in range(1, n + 1, 4):
    for x, y in combinations(list(range(i, i + 4)), 2):
        if x > n or y > n:
            continue
        print(x, y, flush=True)
        if input().strip() == "Ljos!":
            exit(0)
