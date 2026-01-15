#!/usr/bin/env python3

import re
import sys

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*)\n$", line)
i = int(line)
assert 1 <= i <= 3

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*)\n$", line)
n = int(line)
assert 3 <= n <= 100

if i >= 2:
    line = sys.stdin.readline()
    assert re.match("^(0|[1-9][0-9]*)\n$", line)
    m = int(line)
    assert 3 <= m <= 100

if i >= 3:
    line = sys.stdin.readline()
    assert re.match("^(0|[1-9][0-9]*)\n$", line)
    h = int(line)
    assert 3 <= h <= 100

assert not sys.stdin.read()
sys.exit(42)
