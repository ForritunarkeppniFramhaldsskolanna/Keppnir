#!/usr/bin/env python3
from string import ascii_lowercase, ascii_uppercase

s = input()
o = 0
letters = ascii_lowercase[1:] + ascii_uppercase[1:]

for c in s:
    o += c in letters

print(o)
