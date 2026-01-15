#!/usr/bin/python3
import sys
import re

monotone = False
max_c = 3
max_x = 10**8 - 1

exec(sys.argv[1])  # monotone
exec(sys.argv[2])  # max_x
exec(sys.argv[3])  # max_c

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* (0|[1-9][0-9]*)\n$", line)
A, X = map(int, line.strip().split())

assert 1 <= A <= 5
assert 0 <= X <= max_x

for i in range(A):
    line = sys.stdin.readline()
    assert re.match("^[+\-*/] [0-9] [0-3]\n$", line)
    op, y, c = line.strip().split()
    y, c = int(y), int(c)
    if op == "/":
        assert y != 0

assert not sys.stdin.read()
sys.exit(42)
