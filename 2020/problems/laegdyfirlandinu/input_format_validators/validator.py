import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, m = map(int, line.split())
assert 3 <= n <= 50
assert 3 <= m <= 50

for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]*( [1-9][0-9]*)+\n$', line)
    arr = map(int, line.split())
    assert len(arr) == m
    assert all( 1 <= x <= 10**9 for x in arr )

assert not sys.stdin.read()
sys.exit(42)

