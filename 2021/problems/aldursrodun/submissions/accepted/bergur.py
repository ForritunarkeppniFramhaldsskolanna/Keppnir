#!/usr/bin/env python3
import itertools
from math import gcd
n = int(input())
l = map(int, input().split())
p = list(itertools.permutations(l))
ff = True
for e in p:
    f = True
    for i in range(len(e) - 1):
        if gcd(e[i], e[i + 1]) == 1:
            f = False
            break
    if f:
        for g in e:
            print(g, end = ' ')
        print()
        ff = False
        break
if ff: print('Neibb')
