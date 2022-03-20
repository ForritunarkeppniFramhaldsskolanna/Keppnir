#!/bin/python3
n = int(input())
pairs = [tuple(map(int, input().split())) for i in range(n//2+1)]
for i in range(len(pairs)):
    conflict = False
    s = [False for _ in range(n+1)]
    for j in range(len(pairs)):
        if i == j:
            continue
        a,b = pairs[j]
        if s[a] or s[b]:
            conflict = True
            break
        s[a] = True
        s[b] = True
    if conflict == False:
        print("{} {}".format(*sorted(pairs[i])))
        break
