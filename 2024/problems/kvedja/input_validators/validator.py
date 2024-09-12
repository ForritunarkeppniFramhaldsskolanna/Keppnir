#!/usr/bin/env python3

import re
import sys

min_n = float('inf')
max_n = float('-inf')

for arg in sys.argv[1:]:
    exec(arg)

line = sys.stdin.readline()
assert re.match("^[a-zA-Z]+\n$", line), f"{line}"
assert(min_n <= len(line.strip()) <= max_n), f"{len(line)} {min_n} {max_n}"

assert not sys.stdin.read()
exit(42)
