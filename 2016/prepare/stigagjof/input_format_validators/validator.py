#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('^[a-z0-9]+\n$', s)

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
n = int(n.strip())
assert 1 <= n <= 100

last = 0
for i in range(n):
    s = sys.stdin.readline()
    assert re.match('^[0-9]+ [a-z0-9]+ [0-9]+\n$', s)
    t, curs, x = s.strip().split()
    t = int(t)
    assert 1 <= t <= 360
    assert last <= t
    x = int(x)
    assert 0 <= x <= 100
    last = t

assert sys.stdin.read() == ''
sys.exit(42)
