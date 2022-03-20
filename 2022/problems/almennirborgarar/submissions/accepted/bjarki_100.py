#!/usr/bin/env python3
import sys

n, m = map(int, sys.stdin.readline().strip().split())
arr = list(map(int, sys.stdin.readline().strip().split()))

def okay(mid):
    sm = 0
    for x in arr:
        sm += mid // x
    return sm >= m+1

lo = 0
hi = 1
while not okay(hi):
    hi *= 2

while lo <= hi:
    mid = (lo+hi)//2
    if okay(mid):
        res = mid
        hi = mid - 1
    else:
        lo = mid + 1

print(res)

