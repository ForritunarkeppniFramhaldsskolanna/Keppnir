#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^(0|[1-9][0-9]*) [1-9][0-9]*\n$', line)
p, w = map(int, line.split())
assert 0 <= p <= 100
assert 1 <= w <= 10**6

assert not sys.stdin.read()
sys.exit(42)
