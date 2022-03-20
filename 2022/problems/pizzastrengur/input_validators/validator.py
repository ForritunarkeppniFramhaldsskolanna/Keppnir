#!/usr/bin/env python3
import sys
import re

line = sys.stdin.readline()
assert line in ["random\n", "adaptive\n"]

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)

n, m = map(int, line.split())
assert 1 <= n <= 10**3
assert 1 <= m <= 4*n

line = sys.stdin.readline()
assert re.match('^[PIZA]*\n$', line)
word = line[:-1]
assert len(word) == n

assert not sys.stdin.read()
sys.exit(42)
