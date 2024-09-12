#!/usr/bin/python3
import re, sys

exec(sys.argv[1]) # max_q
exec(sys.argv[2]) # cycles

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [1-9][0-9]*\n$", line)

n, q = line.split()
n, q = int(n), int(q)
assert 1 <= n <= 1000
assert 1 <= q <= max_q

g = [[] for _ in range(n)]
indeg = [0 for _ in range(n)]

for _ in range(q):
    line = sys.stdin.readline()
    assert re.match("^[01] [1-9][0-9]* [1-9][0-9]*\n$", line)

    o, x, y = line.split()
    o, x, y = int(o), int(x), int(y)
    assert 0 <= o <= 1
    assert 1 <= x <= n
    assert 1 <= y <= n

    if o == 0:
        g[x - 1].append(y - 1)
        indeg[y - 1] += 1

if not cycles:
    q, res = [], []
    for i in range(n):
        if indeg[i] == 0:
            q.append(i)
    while len(q) > 0:
        cur = q[-1]
        q.pop()
        for x in g[cur]:
            indeg[x] -= 1
            if indeg[x] == 0:
                q.append(x)
        res.append(cur)

    assert len(res) == n

assert not sys.stdin.read()
sys.exit(42)
