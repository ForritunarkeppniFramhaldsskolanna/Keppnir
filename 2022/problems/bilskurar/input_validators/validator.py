#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 2*10**5

line = sys.stdin.readline()
houses = set()
assert re.match('^[1-9][0-9]*( [1-9][0-9]*)*\n$', line)
for num in line.split():
    num = int(num)
    assert 1 <= num <= n
    assert num not in houses
    houses.add(num)

assert(len(houses) == n)

line = sys.stdin.readline()
garages = set()
assert re.match('^[1-9][0-9]*( [1-9][0-9]*)*\n$', line)
for num in line.split():
    num = int(num)
    assert 1 <= num <= n
    assert num not in garages
    garages.add(num)

assert(len(garages) == n)

assert not sys.stdin.read()
sys.exit(42)

