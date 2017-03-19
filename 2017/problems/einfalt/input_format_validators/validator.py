#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('^(0|[1-9][0-9]*)\n$', s)
n = int(s)
assert 0 <= n <= 100

assert sys.stdin.read() == ''
sys.exit(42)
