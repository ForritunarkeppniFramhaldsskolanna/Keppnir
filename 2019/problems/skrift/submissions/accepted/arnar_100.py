#!/usr/bin/python2
import sys
n,m,q = map(int, sys.stdin.readline().split())
A = [0]*m
B = [0]*m
sm = 0
from collections import defaultdict
arr = defaultdict(int)
at = 0
for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    A[i] = a
    B[i] = b
for i in range(q):
    x, y = map(int, sys.stdin.readline().split())
    if x == 1:
        at += y
    elif x == 2:
        at -= y
        arr[at] += 1
        arr[at+y] -= 1

cur = 0
at = 0
cnts = defaultdict(int)
for k,v in sorted(arr.items()):
    dist = k-at
    cnts[cur] += dist
    cur += v
    at = k

ind = sorted([i for i in range(m)], key=B.__getitem__, reverse=True)
at = 0
for x in sorted(cnts.items(), reverse=True):
    mx = x[0]
    cnt = x[1]
    while cnt:
        i = ind[at]
        nxt = A[i]
        if nxt == 0:
            at += 1
        else:
            to_rm = min(cnt, nxt)
            sm += B[i]*to_rm*mx
            A[i] -= to_rm
            cnt -= to_rm

print(sm)
