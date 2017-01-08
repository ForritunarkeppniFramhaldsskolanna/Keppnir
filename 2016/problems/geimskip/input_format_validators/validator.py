#!/usr/bin/env python

import re
import sys

def SQ(x):
    return x*x

N = sys.stdin.readline()
assert re.match('^[0-9]+\n$', N)
N = int(N.strip())
assert 0 <= N <= 10**3
ships = []
for _ in range(N):
    line = sys.stdin.readline()
    assert re.match('^-?[0-9]+ -?[0-9]+ -?[0-9]+ [0-9]+\n$', line)
    x, y, z, r = line.split(' ')
    x = int(x)
    y = int(y)
    z = int(z)
    r = int(r)
    assert -10000 <= x <= 10000
    assert -10000 <= y <= 10000
    assert -10000 <= z <= 10000
    assert 1 <= r <= 1000

    for (x2,y2,z2,r2) in ships:
        assert SQ(x2-x) + SQ(y2-y) + SQ(z2-z) > SQ(r+r2)
    ships.append((x,y,z,r))

M = sys.stdin.readline()
assert re.match('^[0-9]+\n$', M)
M = int(M.strip())
assert 0 <= M <= 10**3
for _ in range(M):
    line = sys.stdin.readline()
    assert re.match('^-?[0-9]+ -?[0-9]+ -?[0-9]+ [0-9]+\n$', line)
    x, y, z, r = line.split(' ')
    assert -10000 <= int(x) <= 10000
    assert -10000 <= int(y) <= 10000
    assert -10000 <= int(z) <= 10000
    assert 1 <= int(r) <= 1000

assert sys.stdin.read() == ''
sys.exit(42)
