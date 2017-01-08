#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('^[0-9]+\n$', s)
s = s.strip()
n = int(s)
assert 1 <= n <= 10**4

names = set()
for i in range(n):
    name = sys.stdin.readline()
    assert re.match('^[A-Za-z]{1,100}\n$', name)
    assert name not in names
    names.add(name)

    city = sys.stdin.readline()
    assert re.match('^[A-Za-z]{1,100}\n$', city)

assert sys.stdin.read() == ''
sys.exit(42)
