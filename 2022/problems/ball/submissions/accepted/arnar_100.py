#!/bin/python3
from collections import Counter
n = int(input())
assert n % 2 == 0
pairs = [tuple(map(int, input().split())) for i in range(n//2+1)]
c = Counter()
for a,b in pairs:
    c[a] += 1
    c[b] += 1

a, b = c.most_common(2)
a = a[0]
b = b[0]
if b < a:
    a,b = b,a
print("{} {}".format(a, b))
