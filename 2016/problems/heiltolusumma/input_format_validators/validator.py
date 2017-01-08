#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('^-?[0-9]+\n$', s)
s = s.strip()
n = int(s)
assert -10**9 <= n <= 10**9

assert sys.stdin.read() == ''
sys.exit(42)
