import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, m = map(int, line.split())
assert 1 <= n <= 500
assert 1 <= m <= 500
assert not (n == 1 and m == 1)

for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[<>v^]+\n$', line)
    line = line.strip()
    assert len(line) == m
    assert line[0] != '<'
    assert line[-1] != '>'
    if i == 0:
        assert '^' not in line
    if i == n-1:
        assert 'v' not in line

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
q = int(line)
assert 1 <= q <= 10**4

for i in range(q):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*\n$', line)
    x, y, k = map(int, line.split())
    assert 1 <= x <= n
    assert 1 <= y <= m
    assert 1 <= k <= 10**9

assert not sys.stdin.read()
sys.exit(42)
