import sys
import re

def readline():
    return sys.stdin.readline().rstrip('\n')

def toint(x):
    try:
        v = int(x)
        assert(str(v) == x)
        return v
    except:
        assert(False)

line = readline()
n, m = map(toint, line.split())

assert(2 <= n <= 100000)
assert(n-1 <= m <= min(2*10**5, n*(n-1)//2))

edges = set()
adj = [[] for i in range(n)]
for x in range(m):
    line = readline()
    a, b, c = map(toint, line.split())
    assert(1 <= a <= n)
    assert(1 <= b <= n)
    assert(a != b)
    assert(c in [0,1])
    assert((a,b) not in edges and (b,a) not in edges)
    edges.add((a,b))
    adj[a-1].append(b-1)
    adj[b-1].append(a-1)

vis = [False for i in range(n)]
S = [0]
vis[0] = True
while S:
    at = S.pop()
    for x in adj[at]:
        if not vis[x]:
            vis[x] = True
            S.append(x)

assert(all(vis))
assert(not sys.stdin.read())
sys.exit(42)
