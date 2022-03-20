#!/usr/bin/python3
import sys
import re

MIN_N = 3
MAX_N = 1000

line = sys.stdin.readline()
assert re.match('^[ACGTOV]*\n$', line)
line = line.strip()
sz = len(line)
assert MIN_N <= sz <= MAX_N

assert not sys.stdin.read()
sys.exit(42)
