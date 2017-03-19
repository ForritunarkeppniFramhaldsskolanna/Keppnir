#!/usr/bin/env python

import re
import sys

n = int(sys.stdin.readline())
a, b = map(int, sys.stdin.readline().split())
assert 1 <= n <= 10**18
assert 1 <= a <= b <= n

assert sys.stdin.read() == ''
sys.exit(42)
