#!/usr/bin/python3

import re
import sys

min_n, max_n = 1, 10**3

exec(sys.argv[1])  # min_n
exec(sys.argv[2])  # max_n

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
n = int(line)
assert min_n <= n <= max_n

for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^[1-9][0-9]*\n$", line)
    x = int(line)
    assert 10 <= x <= 10**9

assert not sys.stdin.read()
sys.exit(42)
