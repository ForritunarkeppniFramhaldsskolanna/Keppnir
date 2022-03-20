#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match("^(([1-9][0-9]*)|0)\.[0-9]\n$", line)
k = float(line)
assert 0 <= k <= 200

assert not sys.stdin.read()
sys.exit(42)
