import random
from decimal import *
getcontext().prec = 100
pi = '3.14159265358979323846'

def split(sm, n):
    res = []
    while len(res) < n:
        cur = sm * Decimal(random.random())
        sm -= cur
        cur = '%0.10f' % cur
        if cur == '0.0000000000':
            continue
            # cur = '0.' + ''.join( random.choice(['0','1']) for _ in range(10) )
        res.append(cur)
    return res

n = 35
k = 17

res = split(Decimal(pi) - Decimal('0.0000000002'), k)
# res = split(Decimal(pi), k)
for i in range(n-k):
    res += [ '%0.10f' % Decimal(random.random() / 100000.0) ]

random.shuffle(res)

print(n)
for s in res:
    print(s)

