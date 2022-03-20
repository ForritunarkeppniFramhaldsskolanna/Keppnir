#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^(([1-9][0-9]*)|0) (([1-9][0-9]*)|0)\n$', line)
n, m = map(int, line.split())
assert 0 <= n <= 1000000
assert 0 <= m <= 1000000

assert not sys.stdin.read()
sys.exit(42)
