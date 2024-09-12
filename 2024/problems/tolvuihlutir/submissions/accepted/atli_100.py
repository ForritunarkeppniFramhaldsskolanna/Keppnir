#!/usr/bin/python3
import bisect

n, k, p = map(int, input().strip().split())
inds = dict()
dat = [[] for _ in range(k)]
for (i, x) in enumerate(input().strip().split()):
    inds[x] = i
for _ in range(n):
    s, v, g = input().strip().split()
    v, g = int(v), int(g)
    dat[inds[s]].append((v, g))
mncost = 0
for i in range(k):
    if len(dat[i]) == 0:
        print("O nei!")
        exit(0)
    dat[i].sort()
    mncost += dat[i][0][0]
    nw = [dat[i][0]]
    for j in range(1, len(dat[i])):
        if dat[i][j][1] > nw[-1][1]:
            nw.append(dat[i][j])
    dat[i] = nw
    for j in range(len(dat[i])):
        dat[i][j] = (dat[i][j][1], dat[i][j][0])
if mncost > p:
    print("O nei!")
    exit(0)
lo, hi = 0, 10 ** 9
while hi > lo:
    md = hi - (hi - lo) // 2
    cost = 0
    for i in range(k):
        it = bisect.bisect(dat[i], (md, -1))
        if it == len(dat[i]):
            cost = 10 ** 10
            break
        cost += dat[i][it][1]
    if cost > p:
        hi = md - 1
    else:
        lo = md
print(lo)
