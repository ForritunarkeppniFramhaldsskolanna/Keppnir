#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 10**5

line = sys.stdin.readline()

arr = list(map(int, line.split()))
check = [i+1 for i in range(n)]

assert sorted(arr) == check
assert arr != check

assert not sys.stdin.read()
sys.exit(42)
