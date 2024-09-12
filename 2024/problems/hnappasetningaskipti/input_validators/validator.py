#!/usr/bin/python3
import re, sys

line = sys.stdin.readline()
typ = "((qwerty)|(dvorak)|(bjarki))"
assert re.match("^" + typ + " on " + typ + "\n$", line)
line = sys.stdin.readline()
assert len(line.strip()) > 0
assert len(line) <= 1000
assert line[-1] == "\n"
for c in line[:-1]:
    assert c in "~1234567890-=qwertyuiop[]asdfghjkl;\'zxcvbnm,./ "
assert not sys.stdin.read()
sys.exit(42)
