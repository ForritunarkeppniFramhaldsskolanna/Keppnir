#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[0-1]*\n$', line)
n = len(line.strip())
assert 1 <= n <= 10**5

assert not sys.stdin.read()
sys.exit(42)
