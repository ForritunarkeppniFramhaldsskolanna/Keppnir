#!/usr/env/bin python3
from heapq import heappush, heappop

n, m = [int(x) for x in input().strip().split()]
mp = [[int(x) for x in input().strip().split()] for _ in range(n)]
q = int(input())

for _ in range(q):
    l1, d1, l2, d2 = [int(x) - 1 for x in input().strip().split()]
    dst = [[10 ** 20 for i in range(m)] for j in range(n)]
    dst[l1][d1] = mp[l1][d1]
    pq = []
    heappush(pq, (mp[l1][d1], l1, d1))
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
    print(dst[l2][d2])
