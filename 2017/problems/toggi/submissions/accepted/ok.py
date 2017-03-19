#! /usr/bin/env python3
from math import log
C = int(input())
lo = 0
hi = 1e18
mx = 0
while lo <= hi:
    mid = (lo + hi) // 2
    val = 10**-6 * mid * log(mid, 10)
    if val > C:
        hi = mid - 1
    else:
        mx = max(mx,mid)
        lo = mid + 1

print(int(mx))
        
