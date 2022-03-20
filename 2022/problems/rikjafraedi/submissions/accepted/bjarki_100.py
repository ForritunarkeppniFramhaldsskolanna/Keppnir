#!/usr/bin/env python3
import sys

n, m = map(int, sys.stdin.readline().strip().split())
es = [ [] for _ in range(n) ]
for i in range(m):
    u, v, x, y, z = map(int, sys.stdin.readline().strip().split())
    u -= 1
    v -= 1
    es[u].append((v, x, y, z))
    es[v].append((u, -x, -y, -z))

dist = [ None for i in range(n) ]
for i in range(n):
    if dist[i] is not None:
        continue
    dist[i] = (0,0,0)
    Q = [i]
    while Q:
        cur = Q.pop()
        for (nxt, x, y, z) in es[cur]:
            ndist = (dist[cur][0] + x, dist[cur][1] + y, dist[cur][2] + z)
            if dist[nxt] is None:
                dist[nxt] = ndist
                Q.append(nxt)
            elif dist[nxt] != ndist:
                print('Neibb')
                sys.exit(0)

print('Jebb')

