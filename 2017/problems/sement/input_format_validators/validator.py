#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert re.match('^[0-9]+ [0-9]+\n$', s)
n,k = map(int,s.split())

assert 1 <= n <= 2*10**5
assert 1 <= k <= 2 * 10**18

for i in range(n):
    s = sys.stdin.readline()
    assert re.match('^[0-9]+\n$', s)
    x = int(s) 
    assert 1 <= x <= 10**18

assert(sys.stdin.read() == "")
sys.exit(42)
