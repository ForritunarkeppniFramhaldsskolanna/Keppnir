#!/usr/bin/python3
import re, sys

line = sys.stdin.readline()
assert re.match("^[a-z]{1,20}\n$", line)
assert not sys.stdin.read()
sys.exit(42)
