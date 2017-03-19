import sys
from decimal import *

getcontext().prec = 100

C = int(sys.stdin.readline())


def ok(n):
    return Decimal(n) * Decimal(n).log10() / Decimal(10**6) <= Decimal(C)

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

