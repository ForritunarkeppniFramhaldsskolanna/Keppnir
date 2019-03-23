import sys
import random

# Type of testcase:
#   1: specific
#   2: specific
#   3: specific
#   4: Given values
typ = int(sys.argv[1])
min_n = int(sys.argv[2])
max_n = int(sys.argv[3])
min_weight = int(sys.argv[4])
max_weight = int(sys.argv[5])
if len(sys.argv) > 6:
    random.seed(int(sys.argv[6]))

n = random.randint(min_n, max_n)
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
    edges.append((a+1,b+1,random.randint(min_weight,max_weight)))
    assert(a != b)
    vis.add((min(a,b), max(a,b)))

if typ == 1:
    perm = [i+1 for i in range(n)]
    random.shuffle(perm)
    m = n
    for i in range(m):
        edges.append((perm[i-1], perm[i], random.randint(min_weight, max_weight)))
elif typ == 2 or typ == 4:
    if typ == 2:
        m = random.randint(n-1, min(2*10**5, n*(n-1)//2))
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
                edges.append((possible[at][0]+1, possible[at][1]+1, random.randint(min_weight, max_weight)))
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
                edges.append((a+1, b+1, random.randint(min_weight, max_weight)))
else:
    m = n*(n-1)//2
    for i in range(n):
        for j in range(i+1, n):
            edges.append((i+1, j+1, random.randint(min_weight, max_weight)))
    
sys.stdout.write("%d %d\n"%(n,m))
for e in edges:
    sys.stdout.write("%d %d %d\n" % e)
