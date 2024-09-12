#!/usr/bin/python3

import re, sys

exec(sys.argv[1]) # typ
exec(sys.argv[2]) # sz

defined = set()
referenced = set()

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
n = int(line)
assert 1 <= n <= sz
total_len = 0

for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^[A-Z]+ (0|[1-9][0-9]*)( ([A-Z]+|[a-z]+))*\n$", line)
    line = line.split()
    k = int(line[1])
    assert 0 <= k <= n
    assert len(line) == k + 2
    assert len(line[0]) <= 20
    assert line[0] not in defined
    defined.add(line[0])
    total_len += len(line[0])
    for ref in line[2:]:
        total_len += len(ref)
        assert len(ref) <= 20
    for ref in set(line[2:]):
        if ref[0].isupper():
            if typ == "tree":
                assert ref in defined
                assert ref not in referenced
            if typ == "trivial":
                assert False
            referenced.add(ref)

assert total_len <= 2 * 10 ** 6

for s in referenced:
    assert s in defined

assert not sys.stdin.read()
sys.exit(42)
