#!/usr/bin/env python3
import heapq
import sys

INF = 10**100

n, m = map(int, sys.stdin.readline().strip().split())
gs = list(map(int, sys.stdin.readline().strip().split()))
es1 = [ [] for _ in range(n) ]
es2 = [ [] for _ in range(n) ]
for i in range(m):
    u,v,a,b = map(int, sys.stdin.readline().strip().split())
    u -= 1
    v -= 1
    es1[u].append((v, a))
    es1[v].append((u, a))
    es2[u].append((v, b))
    es2[v].append((u, b))

def dijkstra(es, start):
    Q = []
    heapq.heappush(Q, (0, start))
    dist = [INF]*n
    dist[start] = 0
    while Q:
        d, at = heapq.heappop(Q)
        if d != dist[at]:
            continue
        for (nxt, w) in es[at]:
            if d + w < dist[nxt]:
                dist[nxt] = d + w
                heapq.heappush(Q, (dist[nxt], nxt))
    return dist

A = dijkstra(es1, 0)
B = dijkstra(es2, n-1)

mn = INF
for i in range(n):
    mn = min(mn, A[i] + gs[i] + B[i])

print('%d' % mn)

