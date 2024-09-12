#!/usr/bin/python3
def dfs(graph, start, target):
    visited = set()

    def _dfs(node):
        if node == target:
            return True
        if node in visited:
            return False
        visited.add(node)
        for neighbor in graph[node]:
            if _dfs(neighbor):
                return True
        return False

    return _dfs(start)


n, q = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(q):
    o, x, y = map(int, input().split())
    x -= 1  # Adjust for 0-based indexing
    y -= 1
    if o == 0:
        graph[x].append(y)
    else:
        if dfs(graph, x, y):
            print("Jebb")
        else:
            print("Neibb")
