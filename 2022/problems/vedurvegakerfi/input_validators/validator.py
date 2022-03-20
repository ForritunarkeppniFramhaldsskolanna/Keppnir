#!/usr/bin/python3
import sys
import re

MIN_W = 0
MAX_W = 10**9

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*\n$', line)
n, m, q = map(int, line.split())
assert 1 <= n <= 10**5
assert 1 <= m <= 10**5
assert 1 <= q <= 10**5

MAX_XORED = max(n, q)*2

for i in range(m):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]* [1-9][0-9]* (0|[1-9][0-9]*)\n$', line)
    u, v, w = map(int, line.split())
    assert 1 <= u <= n
    assert 1 <= v <= n
    assert MIN_W <= w <= MAX_W

for j in range(q):
    line = sys.stdin.readline()
    assert re.match('^(0|[1-9][0-9]*) (0|[1-9][0-9]*) (0|[1-9][0-9]*)\n$', line)
    a, b, h = map(int, line.split())
    assert 0 <= a <= MAX_XORED
    assert 0 <= b <= MAX_XORED
    assert 0 <= h <= MAX_W + MAX_XORED


assert not sys.stdin.read()
sys.exit(42)
