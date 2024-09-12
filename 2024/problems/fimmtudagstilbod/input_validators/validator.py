#!/usr/bin/env python3

import re
import sys

min_y = float("inf")
max_y = float("-inf")

for arg in sys.argv[1:]:
    exec(arg)

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
y = int(line)
assert min_y <= y <= max_y, f"{min_y} {y} {max_y}"

assert not sys.stdin.read()
sys.exit(42)
