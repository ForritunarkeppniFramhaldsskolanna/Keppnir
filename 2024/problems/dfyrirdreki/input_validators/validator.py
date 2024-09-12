#!/usr/bin/python3

import re, sys

exec(sys.argv[1]) # min_n
exec(sys.argv[2]) # max_n

for i in range(3):
    line = sys.stdin.readline()
    assert re.match("^0|^-?[1-9][0-9]*\n$", line)
    n = int(line)
    if i == 0:
        assert n != 0

    assert min_n <= n <= max_n

assert not sys.stdin.read()
sys.exit(42)
