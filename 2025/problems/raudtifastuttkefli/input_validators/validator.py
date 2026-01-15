#!/usr/bin/python3

import re
import sys

max_n = 10**3
max_k = 10**9

exec(sys.argv[1])  # max_n
exec(sys.argv[2])  # max_k

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* (0|[1-9][0-9]*)\n$", line)
n, k = map(int, line.strip().split())
assert 1 <= n <= max_n
assert 0 <= k <= max_k

S = 0
for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^(0|[1-9][0-9]*) (0|[1-9][0-9]*)\n$", line)
    l, d = map(int, line.strip().split())
    assert 0 <= l <= 10**5
    assert 0 <= d <= 10**9
    S += l

assert S <= 10**5

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*)\n$", line)
T = int(line)
assert 0 <= T <= 10**9

assert not sys.stdin.read()
sys.exit(42)
