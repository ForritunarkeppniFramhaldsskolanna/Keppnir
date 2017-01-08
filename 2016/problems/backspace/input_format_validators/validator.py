#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('^[a-z<]+\n$', s)
s = s.strip()
assert 0 <= len(s) <= 10**6
left = 0
for c in s:
    if c == '<':
        assert left > 0
        left -= 1
    else:
        left += 1

assert sys.stdin.read() == ''
sys.exit(42)
