#!/usr/env/bin python3
from heapq import heappush, heappop

n, m = [int(x) for x in input().strip().split()]
mp = [[int(x) for x in input().strip().split()] for _ in range(n)]

q = int(input())
eps = []
o1, o2 = 0, 0
if q == 1:
    o1, o2, e1, e2 = [int(x) - 1 for x in input().strip().split()]
    eps.append((e1, e2))
else:
    for i in range(q):
        _, _, e1, e2 = [int(x) - 1 for x in input().strip().split()]
        eps.append((e1, e2))

dst = [[10 ** 20 for i in range(m)] for j in range(n)]
dst[o1][o2] = mp[o1][o2]
pq = []
heappush(pq, (mp[o1][o2], o1, o2))
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


for e1, e2 in eps:
    print(dst[e1][e2])
