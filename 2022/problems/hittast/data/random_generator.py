#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

tp = sys.argv[1]
MIN_N = int(sys.argv[2])
MAX_N = int(sys.argv[3])
MIN_WEIGHT = int(sys.argv[4])
MAX_WEIGHT = int(sys.argv[5])
MIN_STAY = int(sys.argv[6])
MAX_STAY = int(sys.argv[7])
MAX_M = 10**5

n = random.randint(MIN_N, MAX_N)
m = 0
edges = []
vis = set()

def make_tree(ind, l, r):
    if r <= l:
        return
    m = (l+r)//2
    make_tree(ind, l, m)
    make_tree(ind, m+1, r)
    a = ind[random.randint(l, m)]
    b = ind[random.randint(m+1, r)]
    edges.append((a+1, b+1, random.randint(MIN_WEIGHT,MAX_WEIGHT), random.randint(MIN_WEIGHT, MAX_WEIGHT)))
    assert(a != b)
    vis.add((min(a,b), max(a,b)))

if tp == "path":
    perm = [i+1 for i in range(n)]
    random.shuffle(perm)
    m = n-1
    for i in range(m):
        edges.append((perm[i-1], perm[i], random.randint(MIN_WEIGHT, MAX_WEIGHT), random.randint(MIN_WEIGHT, MAX_WEIGHT)))

elif tp == "general" or tp == "tree":
    if tp == "general":
        m = random.randint(n-1, min(MAX_M, n*(n-1)//2))
    else:
        m = n-1
    ind = [i for i in range(n)]
    random.shuffle(ind)
    make_tree(ind, 0, n-1)
    if n <= 5000:
        possible = [(i,j) for i in range(n) for j in range(i+1,n)]
        random.shuffle(possible)
        at = 0
        while len(edges) < m:
            if possible[at] not in vis:
                vis.add(possible[at])
                edges.append((possible[at][0]+1, possible[at][1]+1, random.randint(MIN_WEIGHT, MAX_WEIGHT), random.randint(MIN_WEIGHT, MAX_WEIGHT)))
            at += 1
    else:
        while len(edges) < m:
            a = random.randint(0, n-1)
            b = random.randint(0, n-1)
            if a == b:
                continue
            a,b = min(a,b), max(a,b)
            if (a,b) not in vis:
                vis.add((a,b))
                edges.append((a+1, b+1, random.randint(MIN_WEIGHT, MAX_WEIGHT), random.randint(MIN_WEIGHT, MAX_WEIGHT)))

elif tp == "complete":
    m = n*(n-1)//2
    for i in range(n):
        for j in range(i+1, n):
            edges.append((i+1, j+1, random.randint(MIN_WEIGHT, MAX_WEIGHT), random.randint(MIN_WEIGHT, MAX_WEIGHT)))

g = [random.randint(MIN_STAY, MAX_STAY) for i in range(n)]

print(n, m)
print(*g)
for e in edges:
    print(*e)
