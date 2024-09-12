#!/usr/bin/python3
import itertools
n, c = map(int, input().strip().split())

quests = []
for i in range(n):
    s, a, b = input().strip().split()
    a, b = int(a), int(b)
    bst, ind = -1, -1
    for j in range(len(quests) + 1):
        x = c
        for k in range(j):
            x += quests[k][1] * x + quests[k][2]
        x += a * x + b
        for k in range(j, len(quests)):
            x += quests[k][1] * x + quests[k][2]
        if x > bst:
            bst = x
            ind = j
    quests.insert(ind, (s, a, b))
for q, _, _ in quests:
    print(q)
