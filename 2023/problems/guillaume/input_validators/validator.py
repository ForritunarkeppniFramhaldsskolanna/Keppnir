#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 3*10**5

line = sys.stdin.readline()
for i in range(n):
    assert line[i] in 'ADG'
assert line[n] == '\n'

assert not sys.stdin.read()
sys.exit(42)
