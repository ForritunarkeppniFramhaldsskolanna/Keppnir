#!/usr/bin/python3
import sys
import re

city_name = sys.stdin.readline()
assert re.match("^[A-Z][a-zA-Z]*burg\n$", city_name)


threshold = sys.stdin.readline()
assert re.match("^1\.00|0\.[0-9]{2}\n$", threshold)
threshold = float(threshold)
assert 0 <= threshold <= 1

n = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", n)
n = int(n)
assert 1 <= n <= 10**5


for i in range(n):
    line = sys.stdin.readline()
    assert line in ["plast\n", "ekki plast\n"]

assert not sys.stdin.read()
sys.exit(42)
