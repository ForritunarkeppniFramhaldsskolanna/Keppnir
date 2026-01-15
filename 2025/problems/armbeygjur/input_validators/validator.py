#!/usr/bin/python3

import re
import sys

max_n = 10**18

exec(sys.argv[1])  # max_n

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
n = int(line)
assert 1 <= n <= max_n

assert not sys.stdin.read()
sys.exit(42)
