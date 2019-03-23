import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*\n$', line)
n,m,k = map(int, line.split())

assert 1 <= n <= 250
assert 1 <= m <= 250
assert 1 <= k <= n*m

cs = {}
for _ in range(k):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
    x,y = map(int,line.split())
    assert 1 <= x <= n
    assert 1 <= y <= m
    assert (x,y) not in cs
    cs[(x,y)] = 1

assert not sys.stdin.read()
sys.exit(42)
