#!python3
import sys

sys.setrecursionlimit(10 ** 5 + 10)

class UnionFind:
    def __init__(self, n):
        self.p = [-1 for i in range(n)]
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
        return True

class Node:
    def __init__(self, a, b, x=None):
        if x is None:
            self.l = a.l
            self.r = b.r
            self.x = max(a.x, b.x)
        else:
            self.l = a
            self.r = b
            self.x = x
    def update(self, v):
        self.x = v

class SegmentTree:
    def __init__(self, a):
        self.n = len(a)
        self.arr = [Node(0, 0, 0) for i in range(4 * len(a))]
        self.mk(a, 0, 0, len(a) - 1)
    def mk(self, a, i, l, r):
        m = (l + r) // 2
        if l > r:
            self.arr[i] = Node(l, r, 0)
        elif l == r:
            self.arr[i] = Node(l, r, a[l])
        else:
            self.arr[i] = Node(self.mk(a, 2 * i + 1, l, m), self.mk(a, 2 * i + 2, m + 1, r))
        return self.arr[i]
    def update(self, at, v, i = 0):
        hl, hr = self.arr[i].l, self.arr[i].r
        if at < hl or hr < at:
            return self.arr[i]
        if hl == at and hr == at:
            self.arr[i].update(v)
            return self.arr[i]
        self.arr[i] = Node(self.update(at, v, 2 * i + 1), self.update(at, v, 2 * i + 2))
        return self.arr[i]
    def query(self, l, r, i = 0):
        hl, hr = self.arr[i].l, self.arr[i].r
        if r < hl or hr < l:
            return Node(hl, hr, 0)
        if l <= hl and hr <= r:
            return self.arr[i]
        return Node(self.query(l, r, 2 * i + 1), self.query(l, r, 2 * i + 2))

class HLD:
    def __init__(self, n):
        self.n = n
        self.curhead = 0
        self.curloc = 0
        self.sz = [1 for i in range(n)]
        self.head = [0 for i in range(n)]
        self.parent = [-1 for i in range(n)]
        self.loc = [0 for i in range(n)]
        self.adj = [[] for i in range(n)]
        self.values = SegmentTree([0 for i in range(n)])
    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)
    def update_cost(self, u, v, c):
        if self.parent[v] == u:
            u, v = v, u
        assert(self.parent[u] == v)
        self.values.update(self.loc[u], c)
    def csz(self, u):
        for i in range(len(self.adj[u])):
            if self.adj[u][i] != self.parent[u]:
                self.parent[self.adj[u][i]] = u
                self.sz[u] += self.csz(self.adj[self.parent[self.adj[u][i]]][i])
        return self.sz[u]
    def part(self, u):
        self.head[u] = self.curhead
        self.loc[u] = self.curloc
        self.curloc += 1
        best = -1
        for i in range(len(self.adj[u])):
            if self.adj[u][i] != self.parent[u] and (best == -1 or self.sz[self.adj[u][i]] > self.sz[best]):
                best = self.adj[u][i]
        if best != -1:
            self.part(best)
        for i in range(len(self.adj[u])):
            if self.adj[u][i] != self.parent[u] and self.adj[u][i] != best:
                self.curhead = self.adj[u][i]
                self.part(self.curhead)
    def build(self, r = 0):
        self.curloc = 0
        self.curhead = r
        self.csz(self.curhead)
        self.part(r)
    def lca(self, u, v):
        uat, vat = [], []
        res = -1
        while u != -1:
            uat.append(u)
            u = self.parent[self.head[u]]
        while v != -1:
            vat.append(v)
            v = self.parent[self.head[v]]
        u = len(uat) - 1
        v = len(vat) - 1
        while u >= 0 and v >= 0 and self.head[uat[u]] == self.head[vat[v]]:
            res = uat[u] if self.loc[uat[u]] < self.loc[vat[v]] else vat[v]
            u -= 1
            v -= 1
        return res
    def query_upto(self, u, v):
        res = 0
        while self.head[u] != self.head[v]:
            res = max(res, self.values.query(self.loc[self.head[u]], self.loc[u]).x)
            u = self.parent[self.head[u]]
        return max(res, self.values.query(self.loc[v] + 1, self.loc[u]).x)
    def query(self, u, v):
        l = self.lca(u, v)
        return max(self.query_upto(u, l), self.query_upto(v, l))

n, m = [int(x) for x in input().strip().split()]
mp = [[int(x) for x in input().strip().split()] for i in range(n)]

uf = UnionFind(n * m)
e, ep = [], []

for i in range(n):
    for j in range(m):
        if i > 0:
            e.append([max(mp[i][j], mp[i - 1][j]), i * m + j, (i - 1) * m + j])
        if j > 0:
            e.append([max(mp[i][j], mp[i][j - 1]), i * m + j, i * m + j - 1])
        if i < n - 1:
            e.append([max(mp[i][j], mp[i + 1][j]), i * m + j, (i + 1) * m + j])
        if j < m - 1:
            e.append([max(mp[i][j], mp[i][j + 1]), i * m + j, i * m + j + 1])

e = sorted(e)
hld = HLD(n * m)

for v in e:
    if uf.unite(v[1], v[2]):
        hld.add_edge(v[1], v[2])
        ep.append(v)

hld.build()

for v in ep:
    hld.update_cost(v[1], v[2], v[0])

q = int(input())

for i in range(q):
    l1, d1, l2, d2 = [int(x) - 1 for x in input().strip().split()]
    if l1 == l2 and d1 == d2:
        print(mp[l1][d1])
    else:
        print(hld.query(l1 * m + d1, l2 * m + d2))

