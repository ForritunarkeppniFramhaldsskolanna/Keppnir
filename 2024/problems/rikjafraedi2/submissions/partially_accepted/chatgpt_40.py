#!/usr/bin/python3
from collections import deque
import sys

def bfs(graph, start, goal):
    visited = set()
    queue = deque([start])

    while queue:
        node = queue.popleft()
        if node == goal:
            return True
        if node not in visited:
            visited.add(node)
            queue.extend(graph[node] - visited)
    return False

def main():
    n, q = map(int, sys.stdin.readline().split())
    graph = {i: set() for i in range(1, n + 1)}

    for _ in range(q):
        o, x, y = map(int, sys.stdin.readline().split())
        if o == 0:
            graph[x].add(y)
        else:  # o == 1
            print("Jebb" if bfs(graph, x, y) else "Neibb")

if __name__ == "__main__":
    main()

