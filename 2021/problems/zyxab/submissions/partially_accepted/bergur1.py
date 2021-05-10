#!/usr/bin/env python3
def unique(s):
    for i in range(len(s)):
        for j in range(i + 1, len(s)):
            if s[i] == s[j]:
                return False
    return True

n = int(input())
r = "Neibb"
f = False
for _ in range(n):
    s = input().strip()
    if not unique(s): continue
    if len(s) < 5: continue
    if f and len(r) < len(s): continue
    if f and r > s: continue
    r = s
    f = True
print(r)
