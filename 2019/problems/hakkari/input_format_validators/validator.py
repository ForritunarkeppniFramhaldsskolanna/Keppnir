import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n,m = map(int, line.split())

assert 1 <= n <= 100
assert 1 <= m <= 100
for x in range(n):
    s = sys.stdin.readline().strip()
    for y in s:
        assert y == '.' or y == '*'

assert not sys.stdin.read()
sys.exit(42)
