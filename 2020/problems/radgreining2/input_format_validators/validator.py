import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, m = map(int, line.split())
assert 1 <= n <= 500
assert 1 <= m <= 500

for i in range(m):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]* [GTAC]+\n$', line)
    s, t = line.strip().split()
    s = int(s)
    assert 1 <= s <= n
    assert 1 <= len(t) <= n-s+1

assert not sys.stdin.read()
sys.exit(42)
