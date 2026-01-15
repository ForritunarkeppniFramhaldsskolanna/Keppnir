import sys
import math
from collections import deque

h, w = map(int, sys.stdin.readline().strip().split())
mp = [sys.stdin.readline().strip() for _ in range(h)]
s_x, s_y = -1, -1
for i in range(h):
    for j in range(w):
        if mp[i][j] == "S":
            s_x, s_y = i, j
dst = [[math.inf for _ in range(w)] for _ in range(h)]
dst[s_x][s_y] = 0
q = deque()
q.append((s_x, s_y))
while len(q) > 0:
    x, y = q.popleft()
    for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        nx, ny = x + dx, y + dy
        if nx < 0 or ny < 0 or nx >= h or ny >= w:
            continue
        if dst[nx][ny] != math.inf:
            continue
        if mp[nx][ny] == "#":
            continue
        dst[nx][ny] = dst[x][y] + 1
        q.append((nx, ny))
bst = math.inf
for i in range(h):
    for j in range(w):
        if mp[i][j] != "G":
            continue
        bst = min(bst, dst[i][j])
if bst == math.inf:
    print("thralatlega nettengdur")
else:
    print(bst)
