#!/usr/bin/python3
COST = {'.': 20, 'O': 10, '\\': 25, '/': 25, 'A': 35, '^': 5, 'v': 22}
n, m = map(int, input().split())
grid = [input() for i in range(n)]
print(sum(COST[grid[i][j]] for i in range(n) for j in range(m)))
