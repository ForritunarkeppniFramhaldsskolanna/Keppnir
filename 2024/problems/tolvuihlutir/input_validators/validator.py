#!/usr/bin/python3

import re, sys

exec(sys.argv[1]) # max_n
exec(sys.argv[2]) # max_k
exec(sys.argv[3]) # max_g
exec(sys.argv[4]) # max_t, num per type

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*\n$", line)
n, k, p = map(int, line.split())
assert 1 <= n <= max_n
assert 1 <= k <= min(max_k, n)
assert 1 <= p <= 10 ** 9

str_lens = 0

line = sys.stdin.readline()
assert re.match("^[A-Za-z]+( [A-Za-z]+)*\n$", line)
types = list(line.split())
type2ind = dict()
assert len(types) == k
assert len(set(types)) == k
for s in types:
    assert len(s) <= 20
    str_lens += len(s)
    type2ind[s] = []


for i in range(n):
    line = sys.stdin.readline()
    assert re.match("^[A-Za-z]+ (0|[1-9][0-9]*) (0|[1-9][0-9]*)\n$", line)
    typ, v, g = line.split()
    v, g = int(v), int(g)
    assert 0 <= v <= 10 ** 9
    assert 0 <= g <= max_g
    assert typ in types
    str_lens += len(typ)
    type2ind[typ].append(i)
    assert len(type2ind[typ]) <= max_t

assert str_lens <= 5 * 10 ** 6

assert not sys.stdin.read()
sys.exit(42)
