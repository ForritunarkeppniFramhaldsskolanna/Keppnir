#!/usr/bin/env python3

import re
import sys

min_n = float("inf")
max_n = float("-inf")

for arg in sys.argv[1:]:
    exec(arg)

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
n = int(line)
assert min_n <= n <= max_n, f"{min_n} {n} {max_n}"

assert not sys.stdin.read()
sys.exit(42)
