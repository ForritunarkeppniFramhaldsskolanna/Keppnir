#!/usr/bin/env python3
s = input().strip()
for j in range(len(s)):
    for i in range(len(s) - 1):
        if s[i] == s[i + 1]:
            s = s[:i] + s[i+1:]
            break
print(s)
