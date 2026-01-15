#!/usr/bin/env python3

import sys
import re
import string

upperBound = None
kdivn = None
exec(sys.argv[1])  # upperBound
exec(sys.argv[2])  # kdivn
assert upperBound is not None
assert kdivn is not None

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
k = int(line)
assert 1 <= k <= upperBound

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
n = int(line)
assert 1 <= n <= upperBound

if kdivn:
    assert n % k == 0

for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^[A-Za-z]+ [1-9][0-9]*\n$", line)
    name, weight = line.split()
    assert 1 <= int(weight) <= 100000
    assert 1 <= len(name) <= 10
    for c in name:
        assert c in string.ascii_letters

assert not sys.stdin.read()
sys.exit(42)
