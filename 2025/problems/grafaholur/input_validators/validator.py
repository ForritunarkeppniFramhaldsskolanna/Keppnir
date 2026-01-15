#!/usr/bin/python3

import re
import sys

int_out = False

exec(sys.argv[1])  # int_out

vals = []
for _ in range(5):
    line = sys.stdin.readline()
    assert re.match("^[1-9][0-9]*\n$", line)
    x = int(line)
    assert 1 <= x <= 100
    vals.append(x)

if int_out:
    num = vals[0] * vals[1] * vals[4]
    den = vals[2] * vals[3]
    assert num % den == 0

assert not sys.stdin.read()
sys.exit(42)
