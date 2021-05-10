#!/usr/bin/env python3
from math import gcd
p = []

def left(x):
    return x*2

def right(x):
    return x*2 + 1

def qrec(i, j, x, y, e):
	if x == i and y == j: return p[e]
	m = (i + j)//2
	if y <= m: return qrec(i, m, x, y, left(e))
	if x > m: return qrec(m + 1, j, x, y, right(e))
	return gcd(qrec(i, m, x, m, left(e)), qrec(m + 1, j, m + 1, y, right(e)))

def query(x, y):
	return qrec(0, n - 1, x, y, 1)

def urec(i, j, x, y, e):
    if i == j: p[e] = y
    else:
        m = (i + j)//2
        if x <= m: urec(i, m, x, y, left(e))
        else: urec(m + 1, j, x, y, right(e))
        p[e] = gcd(p[left(e)], p[right(e)])

def update(x, y):
    return urec(0, n - 1, x, y, 1)

n, q = map(int, input().split())
for _ in range(n*5):
    p.append(1)
i = 0
for e in list(map(int, input().split())):
    update(i, e)
    i += 1
for _ in range(q):
    x, y, z = map(int, input().split())
    if x == 1: update(y - 1, z)
    elif x == 2: print(query(y - 1, z - 1))
    else: assert(0)
