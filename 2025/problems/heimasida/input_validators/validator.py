#!/usr/bin/python3

import sys
import string

allowed = set(string.printable)

level = 0

exec(sys.argv[1])  # level

if level == 0:
    allowed = set(string.ascii_letters)
elif level == 2:
    for c in "ÁáÐðÉéÍíÓóÚúÝýÞþÆæÖö":
        allowed.add(c)

for c in string.whitespace:
    if c == " ":
        continue
    if c in allowed:
        allowed.remove(c)

line = sys.stdin.readline()
assert 1 <= len(line) <= 101
assert line[-1] == "\n"
for c in line[:-1]:
    assert c in allowed

assert not sys.stdin.read()
sys.exit(42)
