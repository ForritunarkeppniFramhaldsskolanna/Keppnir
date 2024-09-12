#!/usr/bin/env python3

import re
import sys

exec(sys.argv[1]) # max_digs
exec(sys.argv[2]) # zero_integ

digs = [0, 0]
lines = ["", ""]
for i in range(2):
    lines[i] = sys.stdin.readline()
    assert re.match("^(0|[1-9][0-9]*)\.[0-9]+\n$", lines[i])
    pre, post = lines[i].strip().split('.')
    assert len(pre) <= 5
    if zero_integ:
        assert pre == "0"
        assert post[0] < '5'
    assert len(post) <= max_digs
    if len(post) > 1:
        assert post[-1] != '0'
    digs[i] = len(post)

assert digs[0] > digs[1]

# Check that data is produced by truncating or rounding
if lines[1] == "0.0\n":
    # Always a valid round for large enough power of 10
    pass
elif len(lines[0].split('.')[0]) < len(lines[1].split('.')[0]):
    # Check for edge case where digits of a and b wouldn't align
    assert len(lines[0].split('.')[0]) + 1 == len(lines[1].split('.')[0])
    assert lines[0][0] >= '5'
    assert lines[1][0] == '1'
    assert all(c in ['0', '.', '\n'] for c in lines[1][1:])
else:
    assert len(lines[0].split('.')[0]) == len(lines[1].split('.')[0])
    a = [c for c in lines[0].strip() if c != '.']
    b = [c for c in lines[1].strip() if c != '.']
    disagree = len(b)
    for i in range(len(b)):
        if a[i] != b[i]:
            disagree = i
            break
    # if disagree == len(b) it can be achieved by truncation
    if disagree != len(b):
        if b[disagree] != '0':
            # We are rounding, check if valid rounding
            assert a[disagree + 1] >= '5'
            assert int(b[disagree]) == int(a[disagree]) + 1
        # if b[disagree] == 0 it can be achieved by truncation, if this is true
        print(lines, disagree)
        assert all(c == '0' for c in b[disagree + 1:])

assert not sys.stdin.read()
sys.exit(42)
