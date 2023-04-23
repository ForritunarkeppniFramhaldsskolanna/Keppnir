#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^(0|[1-9][0-9]*)\n$', line)
n = int(line)
assert 0 <= n <= 1000

assert not sys.stdin.read()
sys.exit(42)
