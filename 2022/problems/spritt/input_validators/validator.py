#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, x = map(int, line.split())
assert 1 <= n <= 2*10**6
assert 1 <= x <= 10**9

for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]*\n$', line), line
    c = int(line)
    assert 1 <= c <= 10**9

assert not sys.stdin.read()
sys.exit(42)
