#!/usr/bin/python3
from math import gcd
n = int(input())
vals = sorted(map(int, input().split()[1:]))
for i in vals:
    print("{} {}/{}".format(i, 1, len(vals)))
