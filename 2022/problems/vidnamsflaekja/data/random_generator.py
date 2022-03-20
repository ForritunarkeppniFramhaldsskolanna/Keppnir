#!/usr/bin/python3
import sys
import random
import math

class UnionFind:
    def __init__(self, n):
        self.p = [-1 for i in range(n)]
    def find(self, x):
        if self.p[x] < 0:
            return x
        self.p[x] = self.find(self.p[x])
        return self.p[x]
    def united(self, x, y):
        return self.find(x) == self.find(y)
    def unite(self, x, y):
        xp, yp = self.find(x), self.find(y)
        if xp == yp: return
        if self.p[xp] > self.p[yp]:
            xp, yp = yp, xp
        self.p[xp] += self.p[yp]
        self.p[yp] = xp
        return

random.seed(int(sys.argv[-1]))

typ = int(sys.argv[1])
# 1 is only parallel
# 2 is only serial
# 3 is parallel + serial
# 4 is planar

lookup = sys.argv[2].strip()
# fetches from table handmade cases if there is a match

max_n = 100
max_m = 100000

handmade = {

}

if lookup in handmade:
    print(handmade[lookup])
    exit(0)

# inserts serials and parallels
def splorf(g):
    a = random.randint(0, len(g) - 1)
    b = random.choice(list(g[a]))
    c = len(g)
    g.append(set())
    if random.randint(1, 2) == 1:
        g[a].remove(b)
        g[b].remove(a)
    g[a].add(c)
    g[b].add(c)
    g[c].add(a)
    g[c].add(b)

# Finds k_5 or k_3,3 subgraph and removes one of its edges
def kuratowski_reduce(g):
    for i in range(len(g)):
        for j in g[i]:
            for k in g[j]:
                if i == k:
                    continue
                if k not in g[i]:
                    continue
                for x in g[k]:
                    if x in [i, j]:
                        continue
                    if x not in g[i]:
                        continue
                    if x not in g[j]:
                        continue
                    for y in g[x]:
                        if y in [i, j, k]:
                            continue
                        if y not in g[i]:
                            continue
                        if y not in g[j]:
                            continue
                        if y not in g[k]:
                            continue
                        # i, j, k, x, y is k_5
                        poss = [i, j, k, x, y]
                        random.shuffle(poss)
                        a, b = poss[0], poss[1]
                        g[a].remove(b)
                        g[b].remove(a)
                        return True
    for i1 in range(len(g)): 
        for i2 in g[i1]: 
            for j1 in g[i2]:
                if j1 == i1:
                    continue
                for j2 in g[j1]:
                    if j2 in [i1, i2]:
                        continue
                    if j2 not in g[i1]:
                        continue
                    for k1 in g[j2]:
                        if k1 in [i1, i2, j1]:
                            continue
                        if k1 not in g[i2]:
                            continue
                        for k2 in g[k1]:
                            if k2 in [i1, i2, j1, j2]:
                                continue
                            if k2 not in g[i1]:
                                continue
                            if k2 not in g[j1]:
                                continue
                            # (i1, j1, k1), (i2, j2, k2) is k_3,3
                            a = random.choice([i1, j1, k1])
                            b = random.choice([i2, j2, k2])
                            g[a].remove(b)
                            g[b].remove(a)
                            return True
    return False



if typ == 1:
    # Graph on 2 vertices
    n, m = 2, random.randint(1, max_m)
    print(n, m)
    print(1, 2)
    for i in range(m):
        x = random.randint(1, 1000)
        a, b = random.choice([(1, 2), (2, 1)])
        print(a, b, x)
elif typ == 2:
    # Tree
    n = random.randint(2, max_n)
    m = n - 1
    print(n, m)
    s = random.randint(1, n)
    t = random.randint(1, n)
    while s == t:
        t = random.randint(1, n)
    print(s, t)
    uf = UnionFind(n)
    while m > 0:
        a = random.randint(0, n - 1)
        b = random.randint(0, n - 1)
        if uf.united(a, b):
            continue
        uf.unite(a, b)
        x = random.randint(1, 1000)
        print(a + 1, b + 1, x)
        m -= 1
elif typ == 3:
    # Parallel/Serial reducible
    g = [set(), set()]
    g[0].add(1)
    g[1].add(0)
    while len(g) + 1 <= max_n:
        splorf(g)
    n = len(g)
    init_m = 0
    for v in g:
        init_m += len(v)
    edg = []
    for i in range(len(g)):
        for j in g[i]:
            if j < i:
                continue
            cnt = random.randint(1, max_m // init_m)
            for k in range(cnt):
                x = random.randint(1, 1000)
                edg.append((i, j, x))
    print(n, len(edg))
    print(1, 2)
    for (i, j, x) in edg:
        print(i + 1, j + 1, x)
else:
    n = max_n - 1
    init_m = int(n * math.log2(n))
    g = [set() for i in range(n)]
    for i in range(init_m):
        a = random.randint(0, n - 1)
        b = random.randint(0, n - 1)
        while b == a or b in g[a]:
            b = random.randint(0, n - 1)
        g[a].add(b)
        g[b].add(a)
    while True:
        if not kuratowski_reduce(g):
            break
    # g is now planar, might not be connected
    # first make g connected, will not break planarity
    uf = UnionFind(n)
    for i in range(n):
        for j in g[i]:
            uf.unite(i, j)
    for i in range(n):
        for j in range(n):
            if uf.united(i, j):
                continue
            g[i].add(j)
            g[j].add(i)
            uf.unite(i, j)
    assert(not kuratowski_reduce(g))
    n = len(g)
    init_m = 0
    for v in g:
        init_m += len(v)
    edg = []
    for i in range(len(g)):
        for j in g[i]:
            if j < i:
                continue
            cnt = random.randint(1, max_m // init_m)
            for k in range(cnt):
                x = random.randint(1, 1000)
                edg.append((i, j, x))
    print(n, len(edg))
    s = random.randint(1, n)
    t = random.randint(1, n)
    while s == t:
        t = random.randint(1, n)
    print(s, t)
    for (i, j, x) in edg:
        print(i + 1, j + 1, x)

