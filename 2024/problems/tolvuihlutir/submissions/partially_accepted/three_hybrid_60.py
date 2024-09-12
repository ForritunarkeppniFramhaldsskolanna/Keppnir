#!/usr/bin/python3

n, k, p = map(int, input().strip().split())
names = list(input().strip().split())
parts = [tuple(input().strip().split()) for i in range(n)]
mxg = 0
for i in range(n):
    parts[i] = (parts[i][0], int(parts[i][1]), int(parts[i][2]))
    mxg = max(mxg, parts[i][2])

if k == 1:
    bst = -1
    for i in range(n):
        _, v, g = parts[i]
        if v <= p:
            bst = max(bst, g)
    if bst == -1:
        print("O nei!")
    else:
        print(bst)
elif mxg <= 10 ** 5:
    by_type = [[] for i in range(k)]
    for part in parts:
        by_type[names.index(part[0])].append((part[1], part[2]))
    cur = mxg
    while True:
        sm = 0
        for i in range(k):
            cheapest = 10 ** 10
            for v, g in by_type[i]:
                if g >= cur:
                    cheapest = min(cheapest, v)
            sm += cheapest
        if sm <= p:
            print(cur)
            exit(0)
        cur -= 1
        if cur < 0:
            print("O nei!")
            break
else:
    sm, wrst = 0, 10 ** 10
    for i in range(n):
        _, v, g = parts[i]
        wrst = min(wrst, g)
        sm += v
    if sm > p or k > n:
        print("O nei!")
    else:
        print(wrst)
