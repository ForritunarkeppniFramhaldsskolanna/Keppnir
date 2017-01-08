#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('\d+ \d+\n$', s)
a,b = map(int,s.split())
assert a in range(1,101)
assert b in range(1,101)

assert sys.stdin.read() == ''
sys.exit(42)
