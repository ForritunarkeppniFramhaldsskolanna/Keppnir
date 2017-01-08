#!/usr/bin/env python

import re
import sys

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
n = int(n.strip()) # stofur

m = sys.stdin.readline()
assert re.match('^[0-9]+\n$', m)
m = int(m.strip()) # keppendur

assert 1 <= n
assert 1 <= m
assert m >= n
assert n <= 10
assert m <= 500

assert sys.stdin.read() == ''
sys.exit(42)
