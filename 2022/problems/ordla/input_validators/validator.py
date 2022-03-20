#!/usr/bin/python3
import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 500

words = set()
for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[a-z]{5}\n$', line)
    word = line.strip()
    assert word not in words
    words.add(word)

assert not sys.stdin.read()
sys.exit(42)
