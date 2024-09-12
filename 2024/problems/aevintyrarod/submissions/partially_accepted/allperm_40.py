#!/usr/bin/python3
import itertools
n, c = map(int, input().strip().split())

quests = []
for i in range(n):
    s, a, b = input().strip().split()
    a, b = int(a), int(b)
    quests.append((s, a, b))
bst = []
val = -1
for pi in itertools.permutations(range(n)):
    x = c
    for j in pi:
        x += quests[j][1] * x + quests[j][2]
    if x > val:
        bst = pi
        val = x
for j in bst:
    print(quests[j][0])

