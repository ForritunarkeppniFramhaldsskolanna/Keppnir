#!/usr/bin/python3
import sys
import re

from collections import Counter

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
a = int(line)

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
b = int(line)

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
c = int(line)

assert 1 <= a <= 100
assert 1 <= b <= 100
assert 720 <= c <= 1439

assert not sys.stdin.read()
sys.exit(42)
