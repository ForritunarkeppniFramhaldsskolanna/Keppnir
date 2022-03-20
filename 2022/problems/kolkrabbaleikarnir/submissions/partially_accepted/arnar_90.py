#!/usr/bin/python3
from fractions import Fraction
from functools import lru_cache


n, m = map(int, input().split())
mem = [[0 for _ in range(m+1)] for _ in range(n+1)]
for i in range(n+1):
    for j in range(m+1):
        if i == 0 or j == 0:
            mem[i][j] = j
        else:
            mem[i][j] = (mem[i-1][j] + mem[i-1][j-1])/2
res = mem[n][m]
print(res)
