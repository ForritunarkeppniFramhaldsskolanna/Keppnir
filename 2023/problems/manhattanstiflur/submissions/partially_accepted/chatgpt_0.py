#!/usr/bin/python3
def dfs(graph, visited, x, y):
    visited[x][y] = True
    for i, j in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        nx, ny = x + i, y + j
        if 0 <= nx < len(graph) and 0 <= ny < len(graph[0]) and graph[nx][ny] and not visited[nx][ny]:
            dfs(graph, visited, nx, ny)

q = int(input())
n, m = map(int, input().split())

graph = [[True] * (m + 1) for _ in range(n + 1)]
visited = [[False] * (m + 1) for _ in range(n + 1)]

for i in range(q):
    x1, y1, x2, y2 = map(int, input().split())
    for x in range(x1, x2 + 1):
        for y in range(y1, y2 + 1):
            graph[x][y] = False

    # check if (0, 0) is still connected to (n, m)
    dfs(graph, visited, 0, 0)
    if visited[n][m]:
        print(i+1)
        break

if not visited[n][m]:
    print(-1)

