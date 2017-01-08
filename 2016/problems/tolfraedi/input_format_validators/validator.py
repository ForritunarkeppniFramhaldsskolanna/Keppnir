#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('^[0-9]+\n$', s)
Q = int(s.strip())
assert 0 <= Q <= 10**6
theset = {}
for i in range(Q):
    l = sys.stdin.readline()
    sys.stdout.write(l)
    assert re.match('^[AR] [0-9]+\n$', l)
    inp = l.strip().split()
    op = inp[0]
    val = inp[1]
    if op == 'R':
        assert (val in theset and theset[val] > 0)
        theset[val] -= 1
    else:
        if val in theset:
            theset[val] += 1
        else:
            theset[val] = 1

assert sys.stdin.read() == ''
sys.exit(42)
