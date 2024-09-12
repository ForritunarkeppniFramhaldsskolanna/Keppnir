#!/usr/bin/python3
import sys

n, m, s = map(int, sys.stdin.readline().strip().split())

if s == 0:
    monster_time = sum(list(map(int, sys.stdin.readline().strip().split())))

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
else:

    from itertools import permutations

    def floyd_warshall(n):
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    h = map(int, input().split())

    h = sorted(h, reverse=True)

    extra = 0

    dist = [[10**8 for _ in range(20)] for _ in range(20)]

    for i in range(n):
        if i >= s:
            extra += h[i]

    for _ in range(m):
        u, v, t = map(int, input().split())
        u -= 1
        v -= 1
        dist[u][v] = t
        dist[v][u] = t
        
    floyd_warshall(n)

    mn_path = 10**8
    for comb in permutations(range(1, n), n-1):
        sm = 0
        lst = 0
        for c in comb:
            sm += dist[lst][c]
            lst = c
        mn_path = min(mn_path, sm)
            
    print(mn_path + extra)
