#!/usr/bin/python3

import re, sys

exec(sys.argv[1]) # max_n
exec(sys.argv[2]) # min_note
exec(sys.argv[3]) # max_note
exec(sys.argv[4]) # cons

assert 0 <= min_note <= max_note <= 115

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
n = int(line)
assert 1 <= n <= max_n

lst = 0
for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^(0|[1-9][0-9]*)\n$", line)
    x = int(line)
    assert min_note <= x <= max_note
    assert cons or x == 0 or lst == 0
    lst = x

assert not sys.stdin.read()
sys.exit(42)
