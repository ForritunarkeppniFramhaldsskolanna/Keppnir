#!/usr/bin/env python2

import re
import sys

line = sys.stdin.readline()
assert re.match('^[0-9]+\n$', line)

n = int(line.strip())
assert 1 <= n <= 10**5

for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[0-9]+ [0-9]+\n$', line)
    a, b = map(int,line.strip().split())
    assert 1 <= a <= b <= 10**9

line = sys.stdin.readline()
assert re.match('^[0-9]+( [0-9]+)*\n$', line)
arr = map(int,line.strip().split())
assert len(arr) == n
for x in arr:
    assert 1 <= x <= 10**9

assert sys.stdin.read() == ''
sys.exit(42)
