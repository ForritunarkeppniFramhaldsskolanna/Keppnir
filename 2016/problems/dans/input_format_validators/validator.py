#!/usr/bin/env python
import re
import sys

line = sys.stdin.readline()
assert re.match('^[0-9]+ [0-9]+\n$', line)
n,k = map(int,line.strip().split())
assert 1 <= n <= 1000
assert 0 <= k <= 10**9

line = sys.stdin.readline()
assert re.match('^[0-9]+( [0-9]+)*\n$', line)
perm = map(int,line.strip().split())
assert len(perm) == n
for x in perm:
    assert 1 <= x <= n
assert len(set(perm)) == n

assert sys.stdin.read() == ''
sys.exit(42)

