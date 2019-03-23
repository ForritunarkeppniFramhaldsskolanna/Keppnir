#!/usr/bin/python3
n, k = map(int, input().split())
B = list(map(int, input().split()))
from collections import defaultdict
A = defaultdict(int)
for x in B:
    A[x] += 1
print(max(A.values()))
