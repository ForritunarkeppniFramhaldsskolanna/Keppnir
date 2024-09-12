#!/usr/bin/python3
import sys
n, c = map(int, sys.stdin.readline().strip().split())

names, quests, prf, suf = [], [], [], []

for i in range(n):
    s, a, b = sys.stdin.readline().strip().split()
    names.append(s)
    a, b = int(a) + 1, int(b)
    bst, ind = -1, -1
    for j in range(len(quests) + 1):
        x = c
        if j > 0:
            x *= prf[j - 1][0]
            x += prf[j - 1][1]
        x *= a
        x += b
        if j < len(quests):
            x *= suf[j][0]
            x += suf[j][1]
        if x > bst:
            bst = x
            ind = j
    quests.insert(ind, (i, a, b))
    prf.insert(ind, [a, b])
    suf.insert(ind, [a, b])
    for j in range(max(ind, 1), len(quests)):
        prf[j] = [quests[j][1], quests[j][2]]
        prf[j][1] += prf[j][0] * prf[j - 1][1]
        prf[j][0] *= prf[j - 1][0]
    for j in range(min(ind, len(quests) - 2), -1, -1):
        suf[j] = [quests[j][1], quests[j][2]]
        suf[j][1] *= suf[j + 1][0]
        suf[j][1] += suf[j + 1][1]
        suf[j][0] *= suf[j + 1][0]
for i, _, _ in quests:
    sys.stdout.write(names[i])
    sys.stdout.write("\n")
