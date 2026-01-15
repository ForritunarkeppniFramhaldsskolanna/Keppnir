import collections
import sys

MAX_X = 100000000
MAX_K = 3
MAX_A = 5

dist = [-1 for _ in range(MAX_X)]
op = [" " for _ in range(MAX_A)]
arg = [0 for _ in range(MAX_A)]
cost = [0 for _ in range(MAX_A)]

a, x = map(int, sys.stdin.readline().strip().split())

q = [collections.deque() for _ in range(MAX_K + 1)]

for i in range(a):
    t, u, v = sys.stdin.readline().strip().split()
    op[i] = t
    arg[i] = int(u)
    cost[i] = int(v)

q[0].append(0)
dist[0] = 0
pos, left = 0, 1

while left > 0:
    while len(q[pos & MAX_K]) == 0:
        pos += 1
    pos &= MAX_K
    cur = q[pos][0]
    q[pos].popleft()
    left -= 1
    if (dist[cur] & MAX_K) != pos:
        continue
    for i in range(a):
        z = cur
        if op[i] == "+":
            z += arg[i]
        if op[i] == "-":
            z -= arg[i]
        if op[i] == "*":
            z *= arg[i]
        if op[i] == "/":
            z //= arg[i]
        if z >= MAX_X or z < 0:
            continue
        if dist[z] == -1 or dist[z] > dist[cur] + cost[i]:
            dist[z] = dist[cur] + cost[i]
            q[dist[z] & MAX_K].append(z)
            left += 1
if dist[x] == -1:
    print("Engin leid!")
else:
    print(dist[x])
