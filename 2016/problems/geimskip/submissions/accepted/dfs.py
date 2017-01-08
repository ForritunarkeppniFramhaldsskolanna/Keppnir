#!/usr/bin/python3
import sys
sys.setrecursionlimit(100000)


def edistsq(a, b):
    return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2 + (a[2] - b[2]) ** 2

ships = []
n = int(input())
for i in range(n):
    x, y, z, r = [int(_) for _ in input().split()]
    ships.append(((x, y, z), r))

m = int(input())
bombs = []
for i in range(m):
    x, y, z, r = [int(_) for _ in input().split()]
    bombs.append(((x, y, z), r))

adj = [[] for _ in range(n + m)]
for i, s in enumerate(ships):
    for j, b in enumerate(bombs):
        if edistsq(s[0], b[0]) <= (s[1] + b[1]) ** 2:
            adj[j].append(m + i)
    for j in range(i):
        if edistsq(s[0], ships[j][0]) <= (2 * s[1] + ships[j][1]) ** 2:
            adj[m + i].append(m + j)
        if edistsq(s[0], ships[j][0]) <= (2 * ships[j][1] + s[1]) ** 2:
            adj[m + j].append(m + i)

marked = set()
for i in range(m):
    st = [i]
    while st:
        j = st.pop()
        marked.add(j)
        for k in adj[j]:
            if k not in marked:
                st.append(k)
print(sum(1 for i in range(n) if m + i not in marked))



