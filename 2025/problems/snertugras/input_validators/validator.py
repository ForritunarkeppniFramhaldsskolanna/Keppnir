#!/usr/bin/python3
import sys
import re

max_h = 10**6
max_w = 10**6
max_n = 10**6
allow_wall = 1

exec(sys.argv[1])  # max_h
exec(sys.argv[2])  # max_w
exec(sys.argv[3])  # max_n
exec(sys.argv[4])  # allow_wall

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [1-9][0-9]*\n$", line)
h, w = map(int, line.strip().split())
n = h * w

assert 1 <= h <= max_h
assert 1 <= w <= max_w
assert 1 <= n <= max_n

s_cnt = 0

for _ in range(h):
    line = sys.stdin.readline()
    assert re.match("^[.#GS]+\n$", line)
    assert len(line.strip()) == w
    s_cnt += line.count("S")

assert s_cnt == 1

assert not sys.stdin.read()
sys.exit(42)
