#!/usr/bin/python3
import sys
import re

n = sys.stdin.readline()
k = sys.stdin.readline()
assert re.match('^[0-9]*\n$', n)
assert re.match('^[1-9][0-9]*\n$', k)
assert 0 <= int(n) <= 2*10**9
assert 1 <= int(k) <= 10**3

assert not sys.stdin.read()
sys.exit(42)
