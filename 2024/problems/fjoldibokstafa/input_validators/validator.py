#!/usr/bin/env python3

import re
import sys
import string

min_n = float("inf")
max_n = float("-inf")
lower = None
upper = None
only_valid = None


for arg in sys.argv[1:]:
    exec(arg)

r = "^["

# lowercase
if lower:
    r += "a-z"

# UPPERCASE
if upper:
    r += "A-Z"

if not only_valid:
    r += re.escape(string.punctuation)

r += "]*\n$"

line = sys.stdin.readline()

assert min_n <= len(line) <= max_n
assert re.match(r, line)

assert not sys.stdin.read()
sys.exit(42)
