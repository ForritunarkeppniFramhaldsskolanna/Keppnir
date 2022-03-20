#!/bin/usr/python3

import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*\n$', line)
n, k, d = map(int, line.split())
assert 1 <= n <= 10**3
assert 1 <= k <= 10**3
assert 1 <= d <= 10**3

for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]*\n$', line)
    m = int(line)
    assert 1 <= m <= d

assert not sys.stdin.read()
sys.exit(42)
