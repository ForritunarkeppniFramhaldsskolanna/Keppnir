#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, m = map(int, line.split())
assert 1 <= n <= 2*10**5
assert 2 <= m <= 100000
assert n*m <= 2*10**6

for i in range(m):
    line = sys.stdin.readline()
    assert re.match('^[A-Za-z]*( [A-Za-z])*\n$', line)
    assert len(line) <= 50

for i in range(n):
    line = sys.stdin.readline()
    re.match('^[1-9][0-9]*( [1-9][0-9*]){{{}}}\n'.format(m-1), line)
    assert sorted(map(int, line.split())) == sorted(range(1, m+1))

assert not sys.stdin.read()
sys.exit(42)
