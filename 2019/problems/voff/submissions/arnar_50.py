#!/usr/bin/python3
n, k = map(int, input().split())
B = sorted(map(int, input().split()))
from collections import defaultdict
A = defaultdict(int)
for x in B:
    A[x] += 1
cur = 0
mx = 0
for i in range(101):
    cur += A[i]
    if i >= k:
        cur -= A[i-k]
    mx = max(mx, cur)
print(mx)
