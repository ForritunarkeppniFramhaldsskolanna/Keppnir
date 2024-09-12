#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
use_s = int(sys.argv[3])

min_t = 1
max_t = 10**4

n = random.randint(min_n, max_n)
s = 0
if use_s:
    s = random.randint(0, n)

edges = [[-1 for _ in range(n)] for _ in range(n)]

def create_tree(n):
    seen = [0]
    for u in range(1, n):
        v = random.choice(seen)
        seen.append(u)
        t = random.randint(min_t, max_t)
        edges[u][v] = t
        edges[v][u] = t

create_tree(n)
m = n-1

edges_left = []
for u in range(n):
    for v in range(u+1,n):
        if edges[u][v] == -1:
            edges_left.append((u, v))

random.shuffle(edges_left)
for i in range(random.randint(0, len(edges_left))):
    m += 1
    u, v = edges_left[i]
    t = random.randint(min_t, max_t)
    edges[u][v] = t
    edges[v][u] = t

print(n, m, s)
print(" ".join([str(random.randint(min_t, max_t)) for _ in range(n)]))

for u in range(n):
    for v in range(u+1,n):
        if (edges[u][v] != -1):
            print(u+1, v+1, edges[u][v])

