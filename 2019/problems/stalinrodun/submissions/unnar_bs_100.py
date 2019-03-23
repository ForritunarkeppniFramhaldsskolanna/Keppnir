#!/usr/bin/python2
import sys
n = int(sys.stdin.readline().rstrip('\n'))
L = list(map(int, sys.stdin.readline().split()))

B = []

for l in L:
    lo, hi = 0, len(B)-1
    ans = -1
    while lo <= hi:
        mid = (lo+hi)//2
        if B[mid] <= l:
            ans = mid
            hi = mid-1
        else:
            lo = mid+1
    if ans == -1:
        B.append(l)
    else:
        B[ans] = l

print(len(B))
