#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match(r'^\d+ \d+ \d+ \d+\n$', s)

a,b,c,d = map(int,s.split())

assert 1 <= a <= 150
assert 0 <= b <= 500
assert 0 <= c <= 100
assert 0 <= d <= 50

assert sys.stdin.read() == ''
sys.exit(42)
