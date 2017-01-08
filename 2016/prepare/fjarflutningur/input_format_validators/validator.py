#!/usr/bin/env python

import re
import sys

def read_int():
    line = sys.stdin.readline()
    assert re.match('(0|[1-9]\d*)$', line)
    return int(line)

n = read_int()
assert 1 <= n <= 100000
for _ in range(n):
    assert 1 <= read_int() <= n

q = read_int()
assert 1 <= q <= 120000
for _ in range(q):
    line = sys.stdin.readline()
    assert line[-1:] == '\n'
    parts = line[:-1].split(' ')
    assert len(parts) == 2
    assert parts[0].isdigit() and parts[1].isdigit()
    [a, b] = [int(parts[0]), int(parts[1])]
    assert 1 <= a <= n
    assert 1 <= b <= n
    assert a != b

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
