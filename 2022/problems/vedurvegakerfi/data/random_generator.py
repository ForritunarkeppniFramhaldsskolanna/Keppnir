#!/usr/bin/python3
import sys
import random

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

class Solver:
    def __init__(self, n):
        self.edges = []
        self.nodes = []
        self.uf = UnionFind(n)
        self.par = [-1 for i in range(n)]
        self.id2w = [10 ** 20 for i in range(n)]
    def add_edge(self, a, b, w):
        self.edges.append((w, a, b))
    def preprocess(self):
        self.edges.sort(reverse=True)
        for (w, a, b) in self.edges:
            if self.uf.united(a, b):
                continue
            self.par.append(-1)
            self.id2w.append(w)
            g1 = self.uf.grpid(a)
            g2 = self.uf.grpid(b)
            self.uf.unite(a, b)
            self.par[g1] = self.uf.grpid(a)
            self.par[g2] = self.uf.grpid(b)
        self.nodes = [None for i in range(len(self.par))]
        for i in range(len(self.par) - 1, -1, -1):
            if self.par[i] == -1:
                self.nodes[i] = Node(i, None)
            else:
                self.nodes[i] = Node(i, self.nodes[self.par[i]])
    def query(self, aj, bj, hj):
        anc = lca(self.nodes[aj], self.nodes[bj])
        return self.id2w[anc.ind] >= hj

random.seed(int(sys.argv[-1]))

tp = sys.argv[1]
MIN_N = int(sys.argv[2])
MAX_N = int(sys.argv[3])
MIN_Q = int(sys.argv[4])
MAX_Q = int(sys.argv[5])
MIN_W = int(sys.argv[6])
MAX_W = int(sys.argv[7])
ordq = sys.argv[8]

n = random.randint(MIN_N, MAX_N)
m = 0
q = random.randint(MIN_Q, MAX_Q)

edges = []
edgeset = set()

def make_tree(edg, vis, l, r):
    if r <= l:
        return
    m = (l+r)//2
    make_tree(edg, vis, l, m)
    make_tree(edg, vis, m+1, r)
    a = random.randint(l, m)
    b = random.randint(m+1, r)
    edg.append((a, b, random.randint(MIN_W,MAX_W)))
    vis.add((a, b))
    vis.add((b, a))

if tp == "cycle":
    m = n
    for i in range(m):
        edges.append((i, (i + 1) % n, random.randint(MIN_W, MAX_W)))
elif tp == "complete":
    m = n * (n - 1) // 2
    for i in range(n):
        for j in range(i + 1, n):
            edges.append((i, j, random.randint(MIN_W, MAX_W)))
elif tp == "general":
    m = random.randint(n - 1, min(n * (n - 1) // 2, MAX_N))
    make_tree(edges, edgeset, 0, n - 1)
    while len(edges) < m:
        new_e = (0, 0, 0)
        while new_e[0] == new_e[1] or (new_e[0], new_e[1]) in edgeset:
           new_e = (random.randint(0, n - 1), random.randint(0, n - 1), random.randint(MIN_W, MAX_W))
        edgeset.add((new_e[0], new_e[1]))
        edgeset.add((new_e[1], new_e[0]))
        edges.append(new_e)

jebb_count = 0

print(n, m, q)

if tp != "cycle":
    random.shuffle(edges)

solver = Solver(n)

for (a, b, w) in edges:
    print(a + 1, b + 1, w)
    solver.add_edge(a, b, w)

solver.preprocess()

allh = [random.randint(MIN_W, MAX_W) for i in range(q)]

if ordq == "yes":
    allh.sort(reverse=True)

for j in range(q):
    a = random.randint(0, n - 1)
    b = random.randint(0, n - 1)
    h = allh[j]

    print((a + 1) ^ jebb_count, (b + 1) ^ jebb_count, h ^ jebb_count)

    if solver.query(a, b, h):
        jebb_count += 1
