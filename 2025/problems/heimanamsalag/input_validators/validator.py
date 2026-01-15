#!/usr/bin/python3
import sys
import re

max_n = 10**5
ab_eq = False
max_t = 10**5

exec(sys.argv[1])  # max_n
exec(sys.argv[2])  # ab_eq
exec(sys.argv[3])  # max_t

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*)\n$", line)
n = int(line)

assert 0 <= n <= max_n

for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^(0|[1-9][0-9]*) (0|[1-9][0-9]*) (0|[1-9][0-9]*)\n$", line)
    ai, bi, ti = map(int, line.strip().split())
    assert ai <= bi
    if ab_eq:
        assert ai == bi
    assert 0 <= ai <= 10**9
    assert 0 <= bi <= 10**9
    assert 0 <= ti <= max_t

assert not sys.stdin.read()
sys.exit(42)
