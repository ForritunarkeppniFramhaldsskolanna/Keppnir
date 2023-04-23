#!/usr/bin/env python3
import sys

class GrowingUnionFind:
    def __init__(self):
        self.p = []
        self.ind = dict()

    def find(self, x):
        while self.p[x] >= 0:
            x, self.p[x] = self.p[x], self.p[self.p[x]]
        return x

    def united(self, x, y):
        if x not in self.ind:
            return False
        if y not in self.ind:
            return False
        return self.find(self.ind[x]) == self.find(self.ind[y])

    def unite(self, x, y):
        if x not in self.ind:
            self.ind[x] = len(self.p)
            self.p.append(-1)
        if y not in self.ind:
            self.ind[y] = len(self.p)
            self.p.append(-1)
        xp = self.find(self.ind[x])
        yp = self.find(self.ind[y])
        if xp == yp:
            return
        if self.p[xp] > self.p[yp]:
            xp, yp = yp, xp
        self.p[xp] += self.p[yp]
        self.p[yp] = xp

    def size(self, x):
        if x not in self.ind:
            return 1
        return -self.p[self.find(self.ind[x])]

q = int(input())
n, m = map(int, input().split())

uf = GrowingUnionFind()

for i in range(q):
    x1, y1, x2, y2 =  map(int, input().split())
    
    if x2 < x1:
        x1, x2 = x2, x1
    if y2 < y1:
        y1, y2 = y2, y1

    if y1 == y2:
        if y1 == 0:
            uf.unite(x1 * m + y1, n * m);
        elif y1 == m:
            uf.unite(x1 * m + y1 - 1, n * m + 1);
        else:
            uf.unite(x1 * m + y1 - 1, x1 * m + y1);
    else:
        if x1 == 0:
            uf.unite(x1 * m + y1, n * m + 1);
        elif x1 == n:
            uf.unite((x1 - 1) * m + y1, n * m);
        else:
            uf.unite((x1 - 1) * m + y1, x1 * m + y1);
    
    if uf.united(n * m, n * m + 1):
        print(i+1)
        exit()
print(-1)
