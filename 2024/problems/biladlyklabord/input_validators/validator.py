#!/usr/bin/env python3

import re
import sys

exec(sys.argv[1]) # max_n
exec(sys.argv[2]) # multirepeat

line = sys.stdin.readline()

assert 1 <= len(line) <= max_n

assert line[-1] == "\n"
line = line[:-1]

lst1, lst2 = -1, -2

for c in line:
    if c != ' ':
        assert ord('a') <= ord(c) <= ord('z')
    if not multirepeat:
        assert lst1 != lst2 or lst1 != c
    lst2 = lst1
    lst1 = c

assert not sys.stdin.read()

sys.exit(42)
