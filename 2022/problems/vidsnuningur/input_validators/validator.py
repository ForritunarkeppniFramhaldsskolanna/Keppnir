#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[A-Za-z0-9]+\n$', line)

assert not sys.stdin.read()
sys.exit(42)
