#!/usr/env/bin python3

n, m = [int(x) for x in input().strip().split()]
mp = [list(input().strip()) for i in range(n)]
jmp = [[[-1 for i in range(32)] for j in range(m)] for k in range(n)]

for i in range(n):
    for j in range(m):
        if mp[i][j] == '>':
            jmp[i][j][0] = (i, j + 1)
        elif mp[i][j] == '<':
            jmp[i][j][0] = (i, j - 1)
        elif mp[i][j] == 'v':
            jmp[i][j][0] = (i + 1, j)
        else:
            jmp[i][j][0] = (i - 1, j)

for k in range(1, 32):
    for i in range(n):
        for j in range(m):
            stp = jmp[i][j][k - 1]
            jmp[i][j][k] = jmp[stp[0]][stp[1]][k - 1]

q = int(input())

for i in range(q):
    x, y, k = [int(x) for x in input().strip().split()]
    pos = (x - 1, y - 1)
    for b in range(32):
        if k & (1 << b):
            pos = jmp[pos[0]][pos[1]][b]
    print(pos[0] + 1, pos[1] + 1)
