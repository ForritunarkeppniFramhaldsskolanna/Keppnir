#!/usr/bin/python3

import re
import sys

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*) \? (0|[1-9][0-9]*)\n$", line)
n, symb, m = line.split()
assert 0 <= int(n) <= 1000
assert symb == "?"
assert 0 <= int(m) <= 1000

assert not sys.stdin.read()
sys.exit(42)
