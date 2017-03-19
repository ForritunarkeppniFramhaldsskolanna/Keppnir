import sys
from math import log

C = int(sys.stdin.readline())

# Hack to get correct time limit
if C == 2:
    c = 0
    while (c+1) * log(c+1) / log(10) / 10**6 <= 50:
        c += 1
# End of hack

def ok(n):
    return n * log(n) / log(10) / 10**6 <= C

lo = 1
hi = 1
while ok(hi):
    hi *= 2

res = 0
while lo <= hi:
    mid = (lo+hi)//2
    if ok(mid):
        res = mid
        lo = mid + 1
    else:
        hi = mid - 1

sys.stdout.write('%d\n' % res)

