#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('^[0-9]+\n$', s)
n = int(s.strip())
assert 1 <= n <= 10**5

s = sys.stdin.readline()
assert re.match('^[01]( [01])*\n$', s)

arr = map(int, s.strip().split(' '))
assert len(arr) == n
assert all( c in [0,1] for c in arr )

assert sys.stdin.read() == ''
sys.exit(42)
