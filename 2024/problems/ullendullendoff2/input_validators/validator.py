#!/usr/bin/python3
import re, sys

min_n = float('inf')
max_n = float('-inf')
exec(sys.argv[1]) # min_n
exec(sys.argv[2]) # max_n

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
n = int(line)
assert min_n <= n <= max_n, f"Failed {min_n} <= {n} <= {max_n}"

used_names = set()

for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^[a-z]+\n$", line)
    name = line.rstrip('\n')
    assert name not in used_names
    assert 1 <= len(name) <= 10
    used_names.add(name)

assert not sys.stdin.read()

sys.exit(42)
