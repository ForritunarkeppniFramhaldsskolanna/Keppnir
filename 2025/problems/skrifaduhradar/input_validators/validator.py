#!/usr/bin/python3
import sys
import re

max_n = 10**5
max_t = 10**18
max_sm = 10**14

exec(sys.argv[1])  # max_n
exec(sys.argv[2])  # max_t
exec(sys.argv[3])  # max_sm

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [1-9][0-9]*\n$", line)
n, t = map(int, line.strip().split())

assert 1 <= n <= max_n
assert 1 <= t <= max_t

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*)( (0|[1-9][0-9]*))*\n$", line)
w = list(map(int, line.strip().split()))
assert len(w) == n
for wi in w:
    assert 0 <= wi <= 10**9
assert sum(w) <= max_sm
assert sum(w) != 0

assert not sys.stdin.read()
sys.exit(42)
