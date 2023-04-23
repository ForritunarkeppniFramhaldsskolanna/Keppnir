#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^(0|-?[1-9][0-9]*)\n$', line)
a = int(line)
line = sys.stdin.readline()
assert re.match('^(0|-?[1-9][0-9]*)\n$', line)
b = int(line)
assert -10**9 <= a <= b <= 10**9

assert not sys.stdin.read()
sys.exit(42)
