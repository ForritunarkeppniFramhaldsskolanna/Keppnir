#!/bin/env python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[A-Za-z \'-]*\n$', line)
assert 1 <= len(line.strip()) <= 40

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
a = int(line)

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
b = int(line)

line = sys.stdin.readline()
assert re.match('^(([-]?[1-9][0-9]*)|0)\n$', line)
ab = int(line)

assert a-b == ab or abs(a-b) == ab

assert not sys.stdin.read()
sys.exit(42)
