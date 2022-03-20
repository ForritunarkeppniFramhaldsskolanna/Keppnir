#!/usr/bin/python3
from heapq import heappop, heappush
import sys
INF = 2*10**9
n, m, q = map(int, sys.stdin.readline().split())
adj = [[] for i in range(n)]
for i in range(m):
    u, v, w = map(int, sys.stdin.readline().split())
    u -= 1
    v -= 1
    adj[u].append((v, w))
    adj[v].append((u, w))

jebb_count = 0

def dijkstra(s):
    pq = [(-INF, s)]
    dist = [-1 for _ in range(n)]
    dist[s] = INF
    while len(pq) > 0:
        prio, cur = heappop(pq)
        if dist[cur] != -prio:
            continue
        for v, w in adj[cur]:
            if dist[v] < min(dist[cur], w):
                dist[v] = min(dist[cur], w)
                heappush(pq, (-dist[v], v))
    return dist

dists = [dijkstra(i) for i in range(n)]

def query(a, b, h):
    if dists[a][b] >= h:
        return True
    return False

for j in range(q):
    a, b, h = map(int, input().split())
    a ^= jebb_count
    b ^= jebb_count
    h ^= jebb_count
    
    if query(a-1, b-1, h):
        print("Jebb")
        jebb_count += 1
    else:
        print("Neibb")

