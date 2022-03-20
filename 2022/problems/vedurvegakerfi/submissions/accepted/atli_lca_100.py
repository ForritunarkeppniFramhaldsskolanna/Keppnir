#!/usr/bin/env python3

import sys

class UnionFind:
    def __init__(self, n):
        self.p = [-1 for i in range(n)]
        self.id = [i for i in range(n)]
        self.c = n
        self.idc = n
    def find(self, x):
        while self.p[x] >= 0:
            x, self.p[x] = self.p[x], self.p[self.p[x]]
        return x
    def united(self, x, y):
        return self.find(x) == self.find(y)
    def unite(self, x, y):
        xp = self.find(x)
        yp = self.find(y)
        if xp == yp:
            return
        if self.p[xp] > self.p[yp]:
            xp, yp = yp, xp
        self.p[xp] += self.p[yp]
        self.p[yp] = xp
        self.id[xp] = self.idc
        self.idc += 1
        self.c -= 1
    def size(self, x):
        return -self.p[self.find(x)]
    def grpid(self, x):
        return self.id[self.find(x)]

class Node:
    def __init__(self, ind, par = None):
        self.par = par
        self.ind = ind
        self.depth = 0
        if par is not None:
            self.depth = par.depth + 1
        self.jmp = [None for i in range(20)]
        self.jmp[0] = par
        i = 1
        while (1 << i) <= self.depth:
            self.jmp[i] = self.jmp[i - 1].jmp[i - 1]
            i += 1

def lca(a, b):
    if a is None or b is None:
        return None
    if a.depth < b.depth:
        a, b = b, a
    for j in range(19, -1, -1):
        while a.depth - (1 << j) >= b.depth:
            a = a.jmp[j]
    if a == b:
        return a
    for j in range(19, -1, -1):
        while a.depth >= (1 << j) and a.jmp[j] != b.jmp[j]:
            a = a.jmp[j]
            b = b.jmp[j]
    return a.par

n, m, q = map(int, sys.stdin.readline().strip().split())
edg = []
for i in range(m):
    a, b, w = map(int, sys.stdin.readline().strip().split())
    a -= 1
    b -= 1
    edg.append((w, a, b))
edg.sort(reverse=True)
uf = UnionFind(n)
par = [-1 for i in range(n)]
MAX = 10 ** 20
id2w = [MAX for i in range(n)]
for (w, a, b) in edg:
    if uf.united(a, b):
        continue
    par.append(-1)
    id2w.append(w)
    g1 = uf.grpid(a)
    g2 = uf.grpid(b)
    uf.unite(a, b)
    par[g1] = uf.grpid(a)
    par[g2] = uf.grpid(b)
nodes = [None for i in range(len(par))]
for i in range(len(par) - 1, -1, -1):
    if par[i] == -1:
        nodes[i] = Node(i, None)
    else:
        nodes[i] = Node(i, nodes[par[i]])
x = 0
for i in range(q):
    aj, bj, hj = map(int, sys.stdin.readline().strip().split())
    aj ^= x
    bj ^= x
    hj ^= x
    aj -= 1
    bj -= 1
    anc = lca(nodes[aj], nodes[bj])
    if id2w[anc.ind] >= hj:
        print("Jebb")
        x += 1
    else:
        print("Neibb")
