#!/usr/bin/python3

import re, sys

exec(sys.argv[1]) # max_n
exec(sys.argv[2]) # max_m
exec(sys.argv[3]) # fixed_size

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* (0|[1-9][0-9]*)\n$", line)
n, m = map(int, line.split())
assert 1 <= n <= max_n
assert 0 <= m <= max_m

line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*) (0|[1-9][0-9]*)\n$", line)
ka, kb = map(int, line.split())
if fixed_size:
    assert ka == n
    assert kb == n
else:
    assert 1 <= ka <= 10 ** 18
    assert 1 <= kb <= 10 ** 18

if m != 0:
    line = sys.stdin.readline()
    assert re.match("^(0|[1-9][0-9]*)( (0|[1-9][0-9]*))*\n$", line)
    nums = list(map(int, line.split()))
    assert len(nums) == m
    for ki in nums:
        assert 1 <= ki <= 10 ** 18

assert not sys.stdin.read()
sys.exit(42)
