#!/usr/bin/python3
import sys
import re

MIN_N = 2
MAX_N = 10
MIN_M = 2
MAX_M = 10

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, m = map(int, line.split())
assert MIN_N <= n <= MAX_N
assert MIN_M <= m <= MAX_M

nums = set()
last = 0

for _ in range(n):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]*( [1-9][0-9]*){{{}}}\n$'.format(m-1), line)
    for x in map(int, line.split()):
        assert 1 <= x <= n*m
        assert x not in nums
        nums.add(x)
        last = x

assert last == n*m

assert not sys.stdin.read()
sys.exit(42)
