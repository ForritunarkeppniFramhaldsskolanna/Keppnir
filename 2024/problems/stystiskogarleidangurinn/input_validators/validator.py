#!/usr/bin/python3

import re, sys

exec(sys.argv[1]) # min_n
exec(sys.argv[2]) # max_n
exec(sys.argv[3]) # smite

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [0-9]+ [0-9]+\n$", line)
n, m, s = map(int, line.split())

assert min_n <= n <= max_n
assert m <= n * (n - 1) // 2
if smite == 0:
    assert s == 0
else:
    assert s <= n

monsters = map(int, sys.stdin.readline().split())

for monster in monsters:
    assert 1 <= monster <= 10**4

for _ in range(m):
    u, v, t = map(int, sys.stdin.readline().split())

    assert 1 <= u <= n
    assert 1 <= v <= n
    assert u != v
    assert 1 <= t <= 10**4

assert not sys.stdin.read()
sys.exit(42)
