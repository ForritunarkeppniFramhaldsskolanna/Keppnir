#!/usr/bin/env python2
import sys
input_file = sys.argv[1]
output = sys.stdin.read()

with open(input_file) as f:
    rows, cols = map(int,f.read().split())

if 1 in (rows, cols):
    corr_steps = (rows * cols - 1) * 2
elif rows % 2 == 0 or cols % 2 == 0:
    corr_steps = rows * cols
else:
    corr_steps = rows * cols + 1


try:
    answer = int(output.strip())
    assert answer == corr_steps
except:
    sys.exit(43)

sys.exit(42)
