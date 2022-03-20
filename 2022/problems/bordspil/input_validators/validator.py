#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('(0|[1-9][0-9]*) (0|[1-9][0-9]*)\n$', line)
n,m = [int(x) for x in line.split()]
assert 0 <= n <= 10**9
assert 0 <= m <= 10**9

assert not sys.stdin.read()
sys.exit(42)
