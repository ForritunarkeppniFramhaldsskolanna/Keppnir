#!/usr/bin/python3
from fractions import Fraction
n, c = map(int, input().strip().split())
quests = []
for i in range(n):
    s, a, b = input().strip().split()
    a, b = int(a), int(b)
    frac = 10 ** 100 if a == 0 else Fraction(b, -a)
    quests.append((frac, s))
quests.sort()
for _, q in quests:
    print(q)
