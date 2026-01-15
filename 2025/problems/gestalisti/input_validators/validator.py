#!/usr/bin/python3

import re
import sys
import string

max_n = 100

exec(sys.argv[1])  # max_n

first_line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", first_line)

n = int(first_line.strip())

assert 0 < n <= max_n

commands = ["?", "+", "-"]
allowed_letters = set(string.ascii_lowercase)

for _ in range(n):
    command = sys.stdin.readline()
    assert re.match("^[?+\-] [a-z]+\n$", command)
    name = command.strip().split()[1]
    assert 1 <= len(name) <= 8

assert not sys.stdin.readline()

sys.exit(42)
