#!/usr/bin/python3

import re
import sys

min_n, max_n = 1, 501

exec(sys.argv[1])  # max_n

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
n = int(line)
assert min_n <= n <= max_n

assert not sys.stdin.read()
sys.exit(42)
