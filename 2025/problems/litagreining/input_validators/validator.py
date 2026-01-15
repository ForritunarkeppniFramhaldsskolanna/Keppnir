#!/usr/bin/python3

import re
import sys

unique_vals = False

exec(sys.argv[1])  # unique_vals

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*) (0|[1-9][0-9]*) (0|[1-9][0-9]*)\n$", line)
r, g, b = map(int, line.strip().split())
assert 0 <= r <= 255
assert 0 <= g <= 255
assert 0 <= b <= 255

if unique_vals:
    assert len(set([r, g, b])) == 3

assert not sys.stdin.read()
sys.exit(42)
