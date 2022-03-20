#!/usr/bin/python3
import sys
import re

from collections import deque

POS_NUM = "[1-9][0-9]*"
NUM = "(0|(" + POS_NUM + "))"
PRICE_MIN = 0
PRICE_MAX = 10**4


line = sys.stdin.readline()
assert re.match('^' + POS_NUM + ' ' + POS_NUM + '\n$', line)
n, m = map(int, line.split())
assert 2 <= n <= 1*10**5
assert 1 <= m <= 1*10**5
assert n-1 <= m <= n*(n-1)//2

line = sys.stdin.readline()
assert re.match('^' + NUM + '( ' + NUM + '){' + str(n-1) + '}\n', line)


adj = [[] for _ in range(n)]
edges = set()

for i in range(m):
    line = sys.stdin.readline()
    assert re.match('^' + POS_NUM + ' ' + POS_NUM + ' ' + NUM + ' ' + NUM + '\n$', line)
    u, v, a, b = map(int, line.split())
    assert u != v, "Self-loop found"
    assert 1 <= u <= n, "Invalid vertex id for u"
    assert 1 <= v <= n, "Invalid vertex id for v"
    assert PRICE_MIN <= a <= PRICE_MAX, "Price of edge out of range"
    assert PRICE_MIN <= b <= PRICE_MAX, "Price of edge out of range"
    t = tuple(sorted([u, v]))
    assert t not in edges, "Duplicate edge found"
    edges.add(t)
    u -= 1
    v -= 1
    adj[u].append(v)
    adj[v].append(u)

q = deque()
q.append(0)
vis = set([0])
while len(q) > 0:
    cur = q.popleft()
    for nxt in adj[cur]:
        if nxt not in vis:
            q.append(nxt)
            vis.add(nxt)

assert len(vis) == n, "Graph is not a single component"

assert not sys.stdin.read()
sys.exit(42)
