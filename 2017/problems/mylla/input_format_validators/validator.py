#!/usr/bin/env python

import re
import sys

n = int(sys.stdin.readline())
s = sys.stdin.readline()
assert 1 <= n <= 10**3
assert re.match('^[AH]+\n$', s)
s = s.strip()
assert 0 <= len(s) <= 10**4

assert sys.stdin.read() == ''
sys.exit(42)
