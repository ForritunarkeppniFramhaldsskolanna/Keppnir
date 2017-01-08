#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('^[0-9]+ [0-9]+\n$', s)
n,k = map(int, s.strip().split())
assert 1 <= n <= 10**5
assert 1 <= k <= 10**5

assert sys.stdin.read() == ''
sys.exit(42)
