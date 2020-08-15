#!/usr/env/bin python3
s, t, r = input(), input(), 1
for i in range(len(s)):
    if s[i] != t[i]:
        r += 1
print(r)
