#!/usr/bin/env python3
import re
import sys

line = sys.stdin.readline()
assert re.match("^[1-2]\n", line)

w = ["kjuklingur", "nautakjot"]
inp = [input() for _ in range(int(line))]

if len(inp) == 1:
    assert inp[0] in w
else:
    assert inp[0] in w and inp[1] in w
    assert inp[0] != inp[1]

assert not sys.stdin.read()
sys.exit(42)
