#!/usr/bin/python3
import sys
import re

from collections import Counter

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 10**3

c = Counter()

for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^(0|[1-9][0-9]*)( [1-9][0-9]*)*\n$', line)
    k,*x = map(int, line.split())
    assert 0 <= k <= n
    assert len(x) == len(set(x))
    for val in x:
        assert 1 <= val <= n


assert not sys.stdin.read()
sys.exit(42)
