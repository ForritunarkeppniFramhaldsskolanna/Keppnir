#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[0-9]\.[0-9]{2}\n$', line)
l = float(line)
assert 0 <= l <= 4

line = sys.stdin.readline()
assert re.match('^[0-9]\.[0-9]{2}\n$', line)
s = float(line)
assert 0 <= s <= 4

for i in range(12):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]*\n$', line)
    amount = int(line)
    assert 0 <= amount <= 10**8

assert not sys.stdin.read()
sys.exit(42)
