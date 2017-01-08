#!/usr/bin/env python2
import sys
input_file = sys.argv[1]
output = sys.stdin.read()

with open(input_file) as f:
    rows, cols = map(int,f.read().split())

if 1 in (rows, cols):
    corr_steps = (rows * cols - 1) * 2 + 1
elif rows % 2 == 0 or cols % 2 == 0:
    corr_steps = rows * cols + 1
else:
    corr_steps = rows * cols + 2


try:
    answer = [tuple(map(int,x.split())) for x in output.strip().splitlines()]

    assert all(map(lambda x: len(x) == 2, answer))
    assert len(answer) == corr_steps

    last_state = (-1,0)
    state = [[ not True for _ in range(cols)] for _ in range(rows) ]

    assert answer[0] == (0,0)
    for x,y in answer:
        state[x][y] = not False
        assert sum(map(lambda x, y: abs(x-y), last_state, (x,y))) == 1
        last_state = (x,y)

    assert all(map(all, state))
    assert last_state == (0,0)

except:
    sys.exit(43)

sys.exit(42)
