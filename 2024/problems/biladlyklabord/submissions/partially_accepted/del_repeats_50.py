#!/usr/bin/env python3
s = input().strip()
for i in range(ord('a'), ord('z') + 1):
    s = s.replace(chr(i) + chr(i), chr(i))
print(s)
