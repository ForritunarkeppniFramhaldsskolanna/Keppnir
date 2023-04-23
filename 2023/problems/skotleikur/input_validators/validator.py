#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^(0|[1-9][0-9]*)\n$', line)
k = int(line)

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
a = int(line)
assert 1 <= a <= 1000

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
b = int(line)
assert 1 <= b <= 1000

assert 0 <= k <= 10**5 * a
assert 0 <= k <= 10**5 * b

assert not sys.stdin.read()
sys.exit(42)
