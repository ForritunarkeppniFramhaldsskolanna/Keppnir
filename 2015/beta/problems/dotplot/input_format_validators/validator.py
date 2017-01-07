import sys
import re

lines = sys.stdin.readlines()

assert len(lines) >= 2

assert all( line[-1] == '\n' for line in lines )
lines = [ line[:-1] for line in lines ]
assert all( len(line) == len(lines[0]) for line in lines )

columns = lines[:-1]
chars = lines[-1]

assert re.match('^[A-Z]+$', chars)
assert len(chars) == len(set(chars))

assert all( c in ' |' for col in columns for c in col )
assert all( c == '|' for c in columns[-1] )

w = len(columns[0])
started = [0] * w

for col in columns:
    now = []
    for i in range(w):
        cur = 1 if col[i] == '|' else 0
        now.append(cur)
        assert started[i] <= cur

    started = now

assert sys.stdin.read() == ''

sys.exit(42)
