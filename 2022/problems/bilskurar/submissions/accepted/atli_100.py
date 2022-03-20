#!/usr/bin/env python3
def merge(l, r):
    i, j, c, v = 0, 0, 0, []
    while i < len(l) and j < len(r):
        v.append(l[i] if l[i] <= r[j] else r[j])
        if l[i] > r[j]: c += len(l) - i
        if l[i] <= r[j]: i += 1
        else: j += 1
    return c, v + l[i:] + r[j:];

def invnum(v):
    if len(v) < 2: return 0, v;
    m = len(v)//2
    x1, l = invnum(v[:m])
    x2, r = invnum(v[m:])
    x3, v = merge(l, r)
    return x1 + x2 + x3, v

n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))
b = list(map(lambda x: int(x) - 1, input().split()))
c = [0 for _ in range(n)]
for i in range(n): c[a[i]] = i
r, _ = invnum([c[b[i]] for i in range(n)])
print(r)
