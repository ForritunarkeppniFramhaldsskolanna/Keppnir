#!/usr/bin/python3
n = int(input())

adj = {i + 1: {i + 1} for i in range(n)}
while True:
    i = min(adj.keys(), key=lambda x: len(adj[x]))
    j = min(set(adj.keys()) - set(adj[i]), key=lambda x: len(adj[x]))
    adj[i].add(j)
    adj[j].add(i)
    print(i, j, flush=True)
    if input().strip() == "Ljos!":
        exit(0)
