#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line), line
n = int(line)
assert 1 <= n <= 10**15

assert not sys.stdin.read()
sys.exit(42)
