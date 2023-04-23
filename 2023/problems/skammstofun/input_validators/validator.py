#!/usr/bin/python3
import sys
import re

from collections import Counter

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)

line = sys.stdin.readline()
regex = '^[A-Za-z]*( [A-Za-z]*){{{}}}\n$'.format(n-1)
re.match(regex, line)
assert 1 <= len(line) <= 1000

assert not sys.stdin.read()
sys.exit(42)
