#!/usr/bin/env python3
import heapq

n = int(input()) // 5
if n == 0:
    print(1)
    exit(0)
dist = dict()
dist[(0, 0)] = 0
q = []
for i in range(-1, 2):
    for j in range(-1, 2):
        if i == 0 and j == 0:
            continue
        heapq.heappush(q, (1, (i, j)))
        dist[(i, j)] = 1
while len(q) > 0:
    w, pos = heapq.heappop(q)
    if dist[pos] != w:
        continue
    x, y = pos
    for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        npos = (x + dx, y + dy)
        nw = w + 1
        if nw > n:
            continue
        if npos in dist and dist[npos] <= nw:
            continue
        dist[npos] = nw
        heapq.heappush(q, (nw, npos))
    for dx, dy in [(2, 2), (2, -2), (-2, 2), (-2, -2)]:
        npos = (x + dx, y + dy)
        nw = w + 3
        if nw > n:
            continue
        if npos in dist and dist[npos] <= nw:
            continue
        dist[npos] = nw
        heapq.heappush(q, (nw, npos))
print(len(dist))
