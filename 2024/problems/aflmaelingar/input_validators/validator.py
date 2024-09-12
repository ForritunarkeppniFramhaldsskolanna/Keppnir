#!/usr/bin/python3

import re, sys

exec(sys.argv[1]) # K
exec(sys.argv[2]) # q
exec(sys.argv[3]) # is_sample

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* [1-9][0-9]*\n$", line)
K_in, q_in = map(int, line.strip().split())
assert K == K_in
assert q == q_in
    
line = sys.stdin.readline()
assert re.match("^(0|[1-9][0-9]*)( (0|[1-9][0-9]*))*\n$", line)
base = list(map(int, line.strip().split()))
if not is_sample:
    assert len(base) == 300
for x in base:
    assert 0 <= x < 100

assert not sys.stdin.read()
sys.exit(42)
