#!/usr/bin/python3
from fractions import Fraction

def E(n, m):
    if n == 0 or m == 0:
        return (m, 1)
    live = E(n-1, m)
    die = E(n-1, m-1)
    return (live[0]+die[0], 2*live[1])

n, m = map(int, input().split())
res = E(n, m)
print(res[0]/res[1])
