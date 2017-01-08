#!/usr/bin/env python

import re
import sys

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
n = int(n.strip())
assert 1 <= n <= 12

m = sys.stdin.readline()
assert re.match('^[0-9]+\n$', m)
m = int(m.strip())
assert 1 <= m <= 500

s = sys.stdin.readline()
assert re.match('^[a-z]+( [a-z]+)*\n$', s)

names = s.split(' ')
assert len(names) == n
assert len(set(names)) == n

sums = [0]*n

for i in range(m):
    s = sys.stdin.readline()
    assert re.match('^[0-9]+( [0-9]+)*\n$', s)
    pts = s.split(' ')
    assert len(pts) == n
    for j in range(n):
        curpt = int(pts[j])
        assert 0 <= curpt <= 100
        sums[j] += curpt

sums = sorted(sums)
if n > 1:
    assert sums[-1] != sums[-2]

assert sys.stdin.read() == ''
sys.exit(42)
