#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 10**5

first_names = set()
for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[A-Z][a-z]{0,9}( [A-Z][a-z]{0,9})?\n$', line)
    names = line.split()
    first_name = names[0]
    second_name = "" if len(names) == 1 else names[1]
    assert first_name not in first_names, first_name
    first_names.add(first_name)

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
m = int(line)
assert 1 <= m <= 10**5

for i in range(m):
    line = sys.stdin.readline()
    assert re.match('^[A-Z][a-z]{0,19}\n$', line)

assert not sys.stdin.read()
sys.exit(42)
