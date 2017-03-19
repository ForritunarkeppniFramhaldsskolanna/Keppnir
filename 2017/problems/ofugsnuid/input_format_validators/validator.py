#!/usr/bin/env python

import re
import sys

n = int(sys.stdin.readline())
assert 1 <= n <= 10**5
for x in range(n):
    a = int(sys.stdin.readline())
    assert 0 <= a <= 10**9

assert sys.stdin.read() == ''
sys.exit(42)
