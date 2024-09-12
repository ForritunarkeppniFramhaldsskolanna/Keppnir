#!/usr/bin/python3

# NOTE: THIS IS ONLY FAST ENOUGH IN PYTHON 3.10+

import sys
sys.setrecursionlimit(1<<15)

class union_find:
    def __init__(self, n):
        self.n = n
        self.p = [-1 for _ in range(n)]
    
    def find(self, x):
        return x if self.p[x] < 0 else self.find(self.p[x])
    
    def unite(self, x, y):
        xp = self.find(x)
        yp = self.find(y)
        if xp == yp:
            return False
        if self.p[xp] > self.p[yp]:
            xp, yp = yp, xp
        self.p[xp] += self.p[yp]
        self.p[yp] = xp
        return True
    
    def size(self, x):
        return -self.p[self.find(x)]

def scc(adj, rev):
    n = len(adj)
    visited = [False for _ in range(n)]
    order = []
    def scc_dfs(adj, u):
        visited[u] = True
        for v in adj[u]:
            if not visited[v]:
                scc_dfs(adj, v)
        order.append(u)
    
    uf = union_find(n)

    for u in range(n):
        if not visited[u]:
            scc_dfs(rev, u)

    visited = [False for _ in range(n)]
    dag = []
    S = []
    for i in range(n - 1, -1, -1):
        if visited[order[i]]:
            continue
        S.append(order[i])
        dag.append(order[i])
        while S:
            u = S.pop()
            visited[u] = True
            uf.unite(u, order[i])
            for v in adj[u]:
                if not visited[v]:
                    S.append(v)
    return uf, dag


if __name__ == "__main__":
    n = int(input())

    mapper = dict()
    acronyms = []
    rev = [[] for _ in range(n)]
    adj = [[] for _ in range(n)]
    for i in range(n):
        acronym, k, *words = input().split()
        acronyms.append(acronym)
        u = mapper.setdefault(acronym, len(mapper))
        for word in words:
            if word.isupper():
                v = mapper.setdefault(word, len(mapper))
                rev[v].append(u)
                adj[u].append(v)

    uf, order = scc(adj, rev)
    
    dag = [[] for _ in range(n)]
    for u in range(n):
        for v in adj[u]:
            if uf.find(u) != uf.find(v):
                dag[uf.find(u)].append(uf.find(v))

    complexity = [0 for i in range(n)]
    for i in range(n):
        complexity[uf.find(i)] += (1 << i)

    for i in order:
        u = uf.find(i)
        for v in dag[u]:
            complexity[u] |= complexity[v]

    def bit_count(n):
        return bin(n).count('1')
    if hasattr(int, 'bit_count'):
        bit_count = int.bit_count

    for acronym in acronyms:
        print(bit_count(complexity[uf.find(mapper[acronym])]))
