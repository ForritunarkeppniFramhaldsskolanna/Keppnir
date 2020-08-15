import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, k = map(int, line.split())

assert 1 <= n <= 10**5
assert 1 <= k <= n

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*( [1-9][0-9]*)+\n$', line)
A = [int(x) for x in line.split()]
for x in A:
    assert 1 <= x <= 32

assert not sys.stdin.read()
sys.exit(42)
