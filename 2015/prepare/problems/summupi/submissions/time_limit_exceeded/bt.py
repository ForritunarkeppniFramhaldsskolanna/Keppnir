from decimal import *
import sys
getcontext().prec = 30
pi = Decimal('3.14159265358979323846')

n = int(raw_input())
arr = []
for i in range(n):
    arr.append(Decimal(raw_input()))

sm = sum(arr)
if sm <= pi:
    print('%0.10f' % sm)
    sys.exit(0)

def bt(at, sm):
    if sm > pi:
        return Decimal('0.0')
    if at == len(arr):
        return sm

    return max(bt(at + 1, sm), bt(at + 1, sm + arr[at]))

print('%0.10f' % bt(0, Decimal('0.0')))

