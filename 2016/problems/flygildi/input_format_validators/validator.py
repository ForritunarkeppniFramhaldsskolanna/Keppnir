#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('^[0-9]+\n$', s)
n = int(s.strip())
assert 1 <= n <= 1000
for i in range(n):
    s = sys.stdin.readline()
    assert re.match('^-?[0-9]+ -?[0-9]+\n$', s)
    x,y = map(int, s.strip().split())
    assert -10**4 <= x <= 10**4
    assert -10**4 <= y <= 10**4

assert sys.stdin.read() == ''
sys.exit(42)
