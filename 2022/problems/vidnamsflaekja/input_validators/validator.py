#!/usr/bin/python3
import sys
import random

class UnionFind:
    def __init__(self, n):
        self.p = [-1 for i in range(n)]
        self.c = n
    def find(self, x):
        if self.p[x] < 0:
            return x
        self.p[x] = self.find(self.p[x])
        return self.p[x]
    def unite(self, x, y):
        xp, yp = self.find(x), self.find(y)
        if xp == yp: return False
        if self.p[xp] > self.p[yp]:
            xp, yp = yp, xp
        self.p[xp] += self.p[yp]
        self.p[yp] = xp
        self.c -= 1
        return True

# Only here to check connectivity since ctd file does not do that

n, m = map(int, input().strip().split())
s, t = map(int, input().strip().split())

uf = UnionFind(n)

for i in range(m):
    a, b, x = map(int, input().strip().split())
    uf.unite(a - 1, b - 1)

assert(uf.c == 1)

sys.exit(42)
