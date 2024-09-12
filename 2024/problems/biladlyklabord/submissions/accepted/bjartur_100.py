#!/usr/bin/env python3
s = input()

o = ""
last = ""

for c in s:
    if c != last:
        o += c
    last = c

print(o)