#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* (0|[1-9][0-9]*)\n$', line, re.MULTILINE)
n, m = map(int, line.strip().split())
assert 1 <= n <= 2*10**5
assert 0 <= m <= 10**9

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*( [1-9][0-9]*)*\n$', line, re.MULTILINE)
arr = list(map(int, line.strip().split()))
assert len(arr) == n

for x in arr:
    assert 1 <= x <= 10**9

assert not sys.stdin.read()
sys.exit(42)
