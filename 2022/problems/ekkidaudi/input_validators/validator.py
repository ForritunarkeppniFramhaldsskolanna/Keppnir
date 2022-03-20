#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[A-z ]+\|[A-z ]+\n$', line)
assert len(line) <= 2100

line = sys.stdin.readline()
assert re.match('^[A-z ]+\|[A-z ]+\n$', line)
assert len(line) <= 2100

assert not sys.stdin.read()
sys.exit(42)
