#!/usr/bin/python3
n, m = map(int, input().split())
adj = [[] for i in range(n)]
for i in range(m):
    a, b, c = map(int, input().split())
    adj[a-1].append((b-1, c))
    adj[b-1].append((a-1, c))

vis = set()
def dfs(at):
    if at == n-1:
        return 0
    vis.add(at)
    if adj[at][0][0] in vis:
        return 1 + dfs(adj[at][1][0])
    #elif adj[at][1][0] in vis:
    return 1 + dfs(adj[at][0][0])
    

d = dfs(0)
print(min(d, n-d))
