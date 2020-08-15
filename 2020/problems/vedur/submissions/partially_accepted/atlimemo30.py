#!/usr/env/bin python3
from heapq import heappush, heappop

n, m = [int(x) for x in input().strip().split()]
mp = [[int(x) for x in input().strip().split()] for _ in range(n)]

dst = [[10 ** 20 for i in range(m)] for j in range(n)]
dst[0][0] = mp[0][0]
pq = []
heappush(pq, (mp[0][0], 0, 0))
while len(pq) > 0:
    cur = heappop(pq)
    if dst[cur[1]][cur[2]] != cur[0]:
        continue
    for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
        nx, ny = cur[1] + dx, cur[2] + dy
        if nx < 0 or nx >= n:
            continue
        if ny < 0 or ny >= m:
            continue
        if dst[nx][ny] <= max(dst[cur[1]][cur[2]], mp[nx][ny]):
            continue
        dst[nx][ny] = max(dst[cur[1]][cur[2]], mp[nx][ny])
        heappush(pq, (dst[nx][ny], nx, ny))

q = int(input())

for _ in range(q):
    a, b, c, d = [int(x) for x in input().strip().split()]
    print(dst[c - 1][d - 1])
