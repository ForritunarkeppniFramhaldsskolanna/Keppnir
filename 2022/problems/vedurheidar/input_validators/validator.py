#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match("^[0-9]*\n$", line)
v = int(line)
assert 0 <= v <= 200
line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
n = int(line)
assert 1 <= n <= 100

for i in range(n):
    line = sys.stdin.readline()
    assert re.match("^[A-Z][a-z]* [0-9]*\n$", line)
    s, k = line.split()
    k = int(k)
    assert 0 <= k <= 200

assert not sys.stdin.read()
sys.exit(42)
