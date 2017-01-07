import sys
import re

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
n = int(n.strip())
assert 1 <= n <= 6

y = sys.stdin.readline()
assert re.match('^[0-9]+( [0-9]+)*\n$', y)
y = map(int, y.strip().split())
assert len(y) == n
for yi in y:
    assert 0 <= yi <= 100

assert sys.stdin.read() == ''

sys.exit(42)
