#!/usr/bin/python3
n, m, q = map(int, input().split())
adj = [[] for i in range(n)]
for i in range(m):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append((v, w))
    adj[v].append((u, w))

jebb_count = 0

def dfs(u, h, vis=None):
    if vis is None:
        vis = set()
    if u not in vis:
        vis.add(u)
        for v, w in adj[u]:
            if w >= h:
                dfs(v, h, vis)
    return vis

def query(a, b, h):
    vis = dfs(a, h)
    if b in vis:
        return True
    return False

for j in range(q):
    a, b, h = map(int, input().split())
    a ^= jebb_count
    b ^= jebb_count
    h ^= jebb_count
    
    if query(a-1, b-1, h):
        print("Jebb")
        jebb_count += 1
    else:
        print("Neibb")

