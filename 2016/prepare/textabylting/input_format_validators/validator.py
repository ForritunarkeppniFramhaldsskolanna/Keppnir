#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('^[0-9]+\n$', s)
n = int(s.strip())
assert 1 <= n <= 100

for i in range(n):
    s = sys.stdin.readline()
    assert re.match('^[A-Za-z0-9]+( [A-Za-z0-9]+)*\n$', s)

assert sys.stdin.read() == ''
sys.exit(42)
