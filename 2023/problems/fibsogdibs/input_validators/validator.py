#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
a, b = map(int, line.split())
assert 1 <= a <= 10**5
assert 1 <= b <= 10**5
assert a <= b

line = sys.stdin.readline()
assert re.match('^[0-9][0-9]*\n$', line)
n = int(line)
assert 0 <= n <= 10**12

assert not sys.stdin.read()
sys.exit(42)
