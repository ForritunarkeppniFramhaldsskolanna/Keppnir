#!/usr/bin/env python3
s = input()
count = 0

for c in s:
    count += c.isascii() and c.isalpha()

print(count)
