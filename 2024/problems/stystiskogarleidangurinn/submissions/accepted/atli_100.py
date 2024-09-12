#!/usr/bin/python3
import sys

n, m, s = map(int, sys.stdin.readline().strip().split())
monster_time = sum(sorted(list(map(int, sys.stdin.readline().strip().split())))[:n - s])

g = [[10 ** 6 if i != j else 0 for i in range(n)] for j in range(n)]
for _ in range(m):
    u, v, t = map(int, sys.stdin.readline().strip().split())
    u, v = u - 1, v - 1
    g[u][v] = min(g[u][v], t)
    g[v][u] = min(g[v][u], t)

for k in range(n):
    for i in range(n):
        for j in range(n):
            g[i][j] = min(g[i][j], g[i][k] + g[k][j])

dp = [[10 ** 6 for _ in range(1 << n)] for _ in range(n)]
dp[0][1] = 0

for j in range(1 << n):
    for i in range(n):
        if j == (1 | (1 << i)):
            dp[i][j] = g[0][i]
            continue
        if not (j & (1 << i)):
            continue
        mn = 10 ** 6
        for k in range(1, n):
            if k == i:
                continue
            if not (j & (1 << k)):
                continue
            val = dp[k][j ^ (1 << i)]
            if val == 10 ** 6 or g[k][i] == 10 ** 6:
                continue
            mn = min(mn, val + g[k][i])
        dp[i][j] = mn

print(min(dp[i][(1 << n) - 1] for i in range(n)) + monster_time)
