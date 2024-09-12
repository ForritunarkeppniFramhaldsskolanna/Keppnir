#!/usr/bin/python3
n, c = map(int, input().strip().split())

quests = []
for i in range(n):
    s, a, b = input().strip().split()
    a, b = int(a), int(b)
    quests.append((s, a, b))
if n == 1:
    print(quests[0][0])
else:
    s1, a1, b1 = quests[0]
    s2, a2, b2 = quests[1]
    forw = c + a1 * c + b1 + a2 * (a1 * c + b1) + b2
    back = c + a2 * c + b2 + a1 * (a2 * c + b2) + b1
    if forw >= back:
        print(s1)
        print(s2)
    else:
        print(s2)
        print(s1)
