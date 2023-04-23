#!/usr/bin/python3
import sys
import re

from collections import Counter

NOTE = "A[#]?0|B[#b]?0|[ABCDEFG][#b]?[1-7]|C[b]?8|-"

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 2 <= n <= 10**5

for i in range(2):
    line = sys.stdin.readline()
    regex = '^({})( ({})){{{}}}\n$'.format(NOTE, NOTE, n-1)
    assert re.match(regex, line)

assert not sys.stdin.read()
sys.exit(42)
