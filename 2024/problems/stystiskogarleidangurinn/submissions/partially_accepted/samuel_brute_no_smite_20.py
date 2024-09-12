#!/usr/bin/python3

from itertools import permutations

def floyd_warshall(n):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

n, m, s = map(int, input().split())

h = map(int, input().split())

h = sorted(h, reverse=True)

extra = 0

dist = [[10**8 for _ in range(20)] for _ in range(20)]

for i in range(n):
    extra += h[i]

for _ in range(m):
    u, v, t = map(int, input().split())
    u -= 1
    v -= 1
    dist[u][v] = t
    dist[v][u] = t
    
floyd_warshall(n)

mn_path = 10**8
for comb in permutations(range(1, n), n-1):
    sm = 0
    lst = 0
    for c in comb:
        sm += dist[lst][c]
        lst = c
    mn_path = min(mn_path, sm)
        
print(mn_path + extra)