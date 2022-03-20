#!/usr/bin/python3

u, k = map(int, input().strip().split())
rec, cnt = dict(), dict()

for i in range(u):
    nm = input().strip()
    rec[nm] = []
    h = int(input())
    for j in range(h):
        s, x = input().strip().split()
        x = int(x)
        rec[nm].append((s, x))

for i in range(k):
    n = int(input())
    for j in range(n):
        s, x = input().strip().split()
        x = int(x)
        if s not in cnt:
            cnt[s] = 0
        cnt[s] += x

cnt2 = dict()
toprnt = []

for k1, v1 in cnt.items():
    for k2, v2 in rec[k1]:
        if k2 not in cnt2:
            cnt2[k2] = 0
            toprnt.append(k2)
        cnt2[k2] += v1 * v2

toprnt.sort()

for k in toprnt:
    print(k, cnt2[k])
