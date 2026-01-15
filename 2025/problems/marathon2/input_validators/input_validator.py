#!/usr/bin/python3
import sys
import re

max_n = 10**6
max_x = 10000
max_y = 100
max_h = 10
FINISH = 42195
hs_eq = False

exec(sys.argv[1])  # hs_eq
exec(sys.argv[2])  # max_n
exec(sys.argv[3])  # max_x

line = sys.stdin.readline()
assert re.match("^[0-9][0-9]* [0-9][0-9]* [0-9][0-9]*\n$", line)
n, x, y = map(int, line.strip().split())

assert 0 <= n <= max_n
assert 0 <= x <= max_x
assert 0 <= y <= max_y

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [1-9][0-9]*\n$", line)
h, s = map(int, line.strip().split())

assert 1 <= h <= 10
assert 1 <= s <= h

if hs_eq:
    assert s == h

for i in range(n):
    line = sys.stdin.readline()
    assert re.match("^[1-9][0-9]*\n$", line)
    station = int(line.strip())

    assert 0 <= station <= FINISH

assert not sys.stdin.read()
sys.exit(42)
