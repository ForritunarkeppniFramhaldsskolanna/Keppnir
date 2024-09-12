#!/usr/bin/python3

import re, sys

exec(sys.argv[1]) # max_n
exec(sys.argv[2]) # max_q

MIN_VAL = 0
MAX_VAL = 10**9

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
n = int(line)
assert 1 <= n <= max_n

names = set()
guesses = set()

for _ in range(n):
    line = sys.stdin.readline()
    assert re.match("^[A-Za-z]+ (0|[1-9][0-9]*)\n$", line)
    name, guess = line.split()
    guess = int(guess)
    assert MIN_VAL <= guess <= MAX_VAL
    assert name not in names
    assert guess not in guesses
    assert len(name) <= 10
    names.add(name)
    guesses.add(guess)

line = sys.stdin.readline()
assert re.match("^[1-9][0-9]*\n$", line)
q = int(line)
assert 1 <= q <= max_q

for _ in range(q):
    line = sys.stdin.readline()
    assert re.match("^(0|[1-9][0-9]*)\n$", line)
    idea = int(line)
    assert MIN_VAL <= idea <= MAX_VAL

assert not sys.stdin.read()
sys.exit(42)
