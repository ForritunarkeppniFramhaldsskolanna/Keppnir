#!/usr/bin/python3
n, k = map(int, input().split())
B = sorted(map(int, input().split()))
from collections import defaultdict
A = defaultdict(int)
for x in B:
    A[x] += 1
keys = sorted(A.keys())
cur = 0
mx = 0
last = []
for i in keys:
    cur += A[i]
    last.append(i)
    j = 0
    while j < len(last) and last[j]+k <= i:
        j += 1
    for l in range(j):
        cur -= A[last[l]]
    last = last[j:]
    mx = max(mx, cur)
print(mx)
