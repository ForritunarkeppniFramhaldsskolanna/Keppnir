#!/usr/bin/python3

import re, sys

exec(sys.argv[1]) # max_n
exec(sys.argv[2]) # coll

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
n = int(line)
assert 1 <= n <= max_n

muls = set()
nams = set()

for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^[0-9A-Za-z._]+ (0|[1-9][0-9]*) (0|[1-9][0-9]*)\n$", line)
    nam, x, y = line.split()
    x, y = int(x), int(y)
    assert 0 <= x <= 100
    assert 0 <= y <= 100
    assert nam not in nams
    assert len(nam) <= 50
    nams.add(nam)
    if coll:
        assert x * y not in muls
    muls.add(x * y)

assert not sys.stdin.read()
sys.exit(42)
