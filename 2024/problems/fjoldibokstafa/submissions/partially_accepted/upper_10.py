#!/usr/bin/env python3
from string import ascii_uppercase

s = input()
o = 0

for c in s:
    o += c in ascii_uppercase

print(o)
