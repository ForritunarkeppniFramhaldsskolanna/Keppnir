#!/usr/env/bin python3
n, k = [int(x) for x in input().strip().split()]
mp = [list(input().strip()) for i in range(n)]
dp = [[0 for j in range(n + 1)] for i in range(n + 1)]
bc = [[0 for j in range(n + 1)] for i in range(n + 1)]
for i in range(n):
    for j in range(n):
        if mp[i][j] == '.':
            continue
        elif mp[i][j] == '#':
            bc[i + 1][j + 1] = 1
        else:
            bc[i + 1][j + 1] = 1
            dp[i + 1][j + 1] = int(mp[i][j])
for i in range(n + 1):
    for j in range(1, n + 1):
        dp[i][j] += dp[i][j - 1]
        bc[i][j] += bc[i][j - 1]
for i in range(1, n + 1):
    for j in range(n + 1):
        dp[i][j] += dp[i - 1][j]
        bc[i][j] += bc[i - 1][j]
mx = 0
for i in range(k, n + 1):
    for j in range(k, n + 1):
        total = bc[i][j] - bc[i - k][j] - bc[i][j - k] + bc[i - k][j - k]
        ip, jp, kp = i - 1, j - 1, k - 2
        inside = bc[ip][jp] - bc[ip - kp][jp] - bc[ip][jp - kp] + bc[ip - kp][jp - kp]
        if total != inside:
            continue
        mx = max(mx, dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k])
print(mx)
