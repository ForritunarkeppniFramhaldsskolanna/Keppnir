import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*\n$', line)
n, m, q = map(int, line.split())

assert 1 <= n <= 10**9
assert 1 <= m <= 10**5
assert 1 <= q <= 10**5

ls = []
for x in range(m):
    line = sys.stdin.readline()
    a,b = map(int, line.split())
    ls.append([a,b])
    assert re.match('^(0|[1-9][0-9]*)( (0|[1-9][0-9]*))*\n$', line)

ls2 = []
for x in range(q):
    line = sys.stdin.readline()
    a,b = map(int, line.split())
    ls2.append([a,b])
    assert re.match('^(0|[1-9][0-9]*)( (0|[1-9][0-9]*))*\n$', line)

assert len(ls) == m
assert len(ls2) == q

for x in ls:
    assert 1 <= x[0] <= n
    assert 1 <= x[1] <= 10**4

sm = 0
for x in ls:
    sm += x[0]
assert sm == n

at = 0
for x in ls2:
    assert 1 <= x[0] <= 2
    assert 1 <= x[1] <= n
    if x[0] == 1:
        at += x[1]
    else:
        at -= x[1]
    assert at >= 0
    assert at <= n

assert not sys.stdin.read()
sys.exit(42)
