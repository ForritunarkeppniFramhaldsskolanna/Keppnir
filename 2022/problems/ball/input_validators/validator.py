#!/usr/bin/python3
import sys
import re

from collections import Counter

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert n % 2 == 0
assert 2 <= n <= 2*10**6

c = Counter()

for i in range(int(n/2)+1):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
    a,b = map(int, line.split())
    assert 1 <= a <= n
    assert 1 <= b <= n
    c[a] += 1
    c[b] += 1

ones = 0
twos = 0
for k in c:
    if c[k] == 1:
        ones += 1
    elif c[k] == 2:
        twos += 1
    else:
        assert False

assert ones == n-2
assert twos == 2


assert not sys.stdin.read()
sys.exit(42)
