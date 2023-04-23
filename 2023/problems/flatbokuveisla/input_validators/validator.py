#!/usr/bin/python3
import sys
import re

from collections import Counter

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 10**6

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
m = int(line)
assert 1 <= m <= 10**6

assert not sys.stdin.read()
sys.exit(42)
