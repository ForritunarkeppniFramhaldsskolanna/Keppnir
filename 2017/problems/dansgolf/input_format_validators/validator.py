#!/usr/bin/env python
import re
import sys

s = sys.stdin.readline().split()
n = int(s[0])
m = int(s[1])
k = int(s[2])
assert 1 <= n <= 10**9
assert 1 <= m <= 10**9
assert 1 <= k <= n*m
assert 1 <= k <= 2*10**5
dis = set()
for x in range(k):
    x,y = map(int,sys.stdin.readline().split())
    assert 1 <= x <= n
    assert 1 <= y <= m
    assert (x,y) not in dis
    dis.add((x,y))

assert sys.stdin.read() == ''
sys.exit(42)
