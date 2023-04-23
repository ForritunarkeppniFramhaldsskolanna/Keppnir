#!/usr/bin/python3
import sys
import re

from collections import Counter

line = sys.stdin.readline()
assert re.match('^[a-z][a-z.@ ]+[a-z.]+\n$', line)
assert line.count('@') == 1
assert line[0].islower()
assert line[-2].islower() or line[-2] == '.'
assert 3 <= len(line) <= 10**6

assert not sys.stdin.read()
sys.exit(42)
