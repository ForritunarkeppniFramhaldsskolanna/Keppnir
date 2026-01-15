#!/usr/bin/python3

import re
import sys

min_n, max_n = 1, 10**5
max_q, allow_b = 10**5, True

exec(sys.argv[1])  # min_n
exec(sys.argv[2])  # max_n
exec(sys.argv[3])  # max_q
exec(sys.argv[4])  # allow_b

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [1-9][0-9]*\n$", line)
n, q = map(int, line.strip().split())
assert min_n <= n <= max_n
assert 1 <= q <= max_q

for _ in range(q):
    line = sys.stdin.readline()
    assert line[0] in ["a", "b", "c"]
    if line[0] == "a":
        assert re.match("^a [1-9][0-9]* [1-9][0-9]*\n$", line)
        x, y = map(int, line[1:].strip().split())
        assert 1 <= x <= n
        assert 1 <= y <= n
    if line[0] == "b":
        assert re.match("^b [1-9][0-9]*\n$", line)
        assert allow_b
        x = int(line[1:])
        assert 1 <= x <= n
    if line[0] == "c":
        assert re.match("^c [1-9][0-9]*\n$", line)
        x = int(line[1:])
        assert 1 <= x <= n

assert not sys.stdin.read()
sys.exit(42)
