#!/usr/bin/env python3
n, p = map(int, input().split())

a = []
b = []
for _ in range(n):
    x, y = map(int, input().split())
    a.append(x - 1)
    b.append(y - 1)

c = [[], [], [], []]
for i in range(4):
    for _ in range(13):
        c[i].append(False)

k = 0
for i in range(n):
    x, y = a[i], b[i]
    c[x][y] = True;
    if y <= 10 and c[x][y + 1] and c[x][y + 2]: break
    if y <= 11 and y >= 1 and c[x][y - 1] and c[x][y + 1]: break
    if y >= 2 and c[x][y - 2] and c[x][y - 1]: break
    k += 1

if k != n: print(max(0, i - p) + 1)
else: print('Neibb')

