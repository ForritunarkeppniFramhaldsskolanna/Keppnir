#!/usr/bin/env python3
import re
import sys

line = sys.stdin.readline()
assert re.match("^[a-zA-Z0-9 ]*\n$", line)
assert len(line) <= 11

assert not sys.stdin.read()
sys.exit(42)
