#!/usr/bin/env python

import re
import sys

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
n = int(n.strip())
assert 1 <= n <= 10**5

seen = set()
for i in range(n):
    s = sys.stdin.readline()
    assert re.match('^[1-9][0-9]{6}\n$', s)
    assert s not in seen
    seen.add(s)

m = sys.stdin.readline()
assert re.match('^[0-9]+\n$', m)
m = int(m.strip())
assert 1 <= m <= 10**5

for i in range(m):
    s = sys.stdin.readline()
    assert re.match('^[1-9][0-9]{0,6}\n$', s)

assert sys.stdin.read() == ''
sys.exit(42)
