import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, m = line.strip().split()
n, m = int(n), int(m)
assert 1 <= n and n <= 2 * 10 ** 5
assert 1 <= m and m <= 2 * 10 ** 5
assert 1 <= n * m and n * m <= 2 * 10 ** 5

for i in range(n):
    line = sys.stdin.readline()
    assert len(line.strip().split()) == m
    for x in line.strip().split():
        assert re.match('^[1-9][0-9]*$', x)
        x = int(x)
        assert 1 <= x and x <= 10 ** 18

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
q = int(line)
assert 1 <= q and q <= 2 * 10 ** 5

for i in range(q):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]* [1-9][0-9]*\n$', line)
    a, b, c, d = line.strip().split()
    a, b, c, d = int(a), int(b), int(c), int(d)
    assert 1 <= a and a <= n
    assert 1 <= b and b <= m
    assert 1 <= c and c <= n
    assert 1 <= d and d <= m

assert not sys.stdin.read()
sys.exit(42)
