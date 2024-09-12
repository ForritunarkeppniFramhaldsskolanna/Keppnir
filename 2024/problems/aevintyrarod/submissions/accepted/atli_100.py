#!/usr/bin/python3
import sys
from functools import cmp_to_key
def quest_sort(x, y):
    if x[1] == 0 and y[1] == 0:
        return 0
    if x[1] == 0:
        return -1
    if y[1] == 0:
        return 1
    return y[2] * x[1] - x[2] * y[1]
n, c = map(int, sys.stdin.readline().strip().split())
quests = []
for i in range(n):
    s, a, b = sys.stdin.readline().strip().split()
    a, b = int(a), int(b)
    quests.append((s, a, b))
quests.sort(key=cmp_to_key(quest_sort))
for q, _, _ in quests:
    sys.stdout.write(q)
    sys.stdout.write("\n")
