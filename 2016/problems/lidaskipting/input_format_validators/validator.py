#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', s)
n = int(s.strip())

assert 1 <= n <= 10**100

assert sys.stdin.read() == ''
sys.exit(42)
