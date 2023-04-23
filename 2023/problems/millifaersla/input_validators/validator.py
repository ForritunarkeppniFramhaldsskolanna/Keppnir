#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
a = int(line)

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
b = int(line)

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
c = int(line)

assert 0 <= a <= 10**9
assert 0 <= b <= 10**9
assert 0 <= c <= 10**9

assert a != b and b != c and a != c

assert not sys.stdin.read()
sys.exit(42)
