#!/usr/bin/env python3
n, cnt = int(input()), 0
xs = [int(x) - 1 for x in input().strip().split()]
dn = [False for i in range(n)]

for i in range(n):
    if dn[i]:
        continue
    dn[i] = True
    if xs[i] == i:
        continue
    pos = xs[i]
    while pos != i:
        cnt += 1
        dn[pos] = True
        pos = xs[pos]
    cnt += 2

print(cnt)

