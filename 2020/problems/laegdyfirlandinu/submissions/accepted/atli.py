#!/usr/env/bin python3
n, m = [int(x) for x in input().strip().split()]
mp = [[int(x) for x in input().strip().split()] for i in range(n)]
lgd = False

for i in range(1, n - 1):
    for j in range(1, m - 1):
        if mp[i][j] >= mp[i + 1][j]:
            continue
        if mp[i][j] >= mp[i - 1][j]:
            continue
        if mp[i][j] >= mp[i][j + 1]:
            continue
        if mp[i][j] >= mp[i][j - 1]:
            continue
        lgd = True
        break
    if lgd:
        break
if lgd:
    print("Jebb")
else:
    print("Neibb")
