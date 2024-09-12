#!/usr/bin/python3
import re, sys

exec(sys.argv[1]) # max_n

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]* (0|[1-9][0-9]*)\n$", line)
n, c = map(int, line.split())
assert 1 <= n <= max_n
assert 0 <= c <= 10 ** 3

used_names = set()
name_len = 0

for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^[A-Za-z]+ (0|[1-9][0-9]*) (0|[1-9][0-9]*)\n$", line)
    name, a, b = line.split()
    a, b = int(a), int(b)
    assert 0 <= a <= 10 ** 3
    assert 0 <= b <= 10 ** 3
    assert name not in used_names
    assert len(name) <= 20
    used_names.add(name)

assert name_len <= 3 * 10 ** 5
assert not sys.stdin.read()

sys.exit(42)
