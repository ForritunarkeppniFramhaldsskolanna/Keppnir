#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('^[0-9]+ [0-9]+\n$', s)
n,m = map(int, s.strip().split())
assert 1 <= n <= 10**12
assert 1 <= m <= 10**5
for i in range(m):
    s = sys.stdin.readline()
    assert re.match('^[0-9]+ [0-9]+\n$', s)
    a,b = map(int, s.split())
    assert 1 <= a <= b <= n

assert sys.stdin.read() == ''
sys.exit(42)
