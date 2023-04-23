#!/usr/bin/python3
import sys
import re

m = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', m)
n = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', n)

m = int(m)
n = int(n)

for lane in range(n):
    line = sys.stdin.readline().strip()
    assert len(line) == m
    for char in line:
        assert char in ['#', '.']

assert not sys.stdin.read()
sys.exit(42)
