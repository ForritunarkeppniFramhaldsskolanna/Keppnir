#!/usr/bin/python3
n = int(input())
d = 2 * n + 3
box = [[' ' for j in range(d)] for i in range(d)]
box[0][n + 1] = 'X'
box[-1][n + 1] = 'X'
box[n + 1][0] = 'X'
box[n + 1][-1] = 'X'
for i in range(1, n + 1):
    box[i][n + 1 - i] = '/'
    box[i][n + 1 + i] = '\\'
    box[i + n + 1][i] = '\\'
    box[n + 1 + i][d - i - 1] = '/'
for l in box:
    print("".join(l).rstrip())
