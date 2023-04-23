#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, m = map(int, line.split())
assert 1 <= n <= 1000
assert 1 <= m <= 1000

for i in range(n):
    line = sys.stdin.readline()
    # need to escape the backslash in the resulting string
    regex = '^[.O/\\\\Av^]{{{}}}\n$'.format(m)
    assert re.match(regex, line), "error on line {}".format(i+2)

assert not sys.stdin.read()
sys.exit(42)
