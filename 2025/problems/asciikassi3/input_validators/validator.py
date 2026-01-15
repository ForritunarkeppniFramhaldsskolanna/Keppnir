#!/usr/bin/python3

import re
import sys

max_h, max_w, max_d = 100, 100, 100
min_h, min_w, min_d = 1, 1, 1

exec(sys.argv[1])  # max_h
exec(sys.argv[2])  # max_w
exec(sys.argv[3])  # max_d

exec(sys.argv[4])  # min_h
exec(sys.argv[5])  # min_w
exec(sys.argv[6])  # min_d

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*\n$", line)
h, w, d = map(int, line.strip().split())
assert min_h <= h <= max_h
assert min_w <= w <= max_w
assert min_d <= d <= max_d

assert not sys.stdin.read()
sys.exit(42)
