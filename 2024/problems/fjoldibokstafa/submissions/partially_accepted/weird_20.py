#!/usr/bin/env python3
from string import ascii_lowercase, ascii_uppercase

s = input()
o = 0

if s.islower():
    for c in s:
        o += c in ascii_lowercase
elif s.isupper():
    for c in s:
        o += c in ascii_uppercase

print(o)
