#!/usr/env/bin python3
n, d = [int(x) for x in input().strip().split()]
x, s, p = [int(y) for y in input().strip().split()], 0, 0

while x[p] != 0:
    s += x[p]
    x[p] = 0
    p += d
    p %= n

print(s)

