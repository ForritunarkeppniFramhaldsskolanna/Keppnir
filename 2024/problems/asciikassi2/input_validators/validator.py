#!/usr/bin/python3

import re, sys

exec(sys.argv[1]) # max_n

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*)\n$", line)
n = int(line)
assert 0 <= n <= max_n

assert not sys.stdin.read()
sys.exit(42)
