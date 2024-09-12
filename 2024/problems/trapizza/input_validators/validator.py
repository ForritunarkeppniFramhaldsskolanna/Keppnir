#!/usr/bin/python3

import re, sys

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*)\n$", line)
d = int(line)
assert 0 <= d <= 100

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*)\n$", line)
a = int(line)
assert 0 <= a <= 100

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*)\n$", line)
b = int(line)
assert 0 <= b <= 100

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*)\n$", line)
h = int(line)
assert 0 <= h <= 100


assert not sys.stdin.read()
sys.exit(42)