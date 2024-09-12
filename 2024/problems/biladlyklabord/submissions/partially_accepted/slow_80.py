#!/usr/bin/env python3
s = input().strip()
while True:
    done = True
    for i in range(len(s) - 1):
        if s[i] == s[i + 1]:
            s = s[:i] + s[i+1:]
            done = False
            break
    if done:
        break
print(s)
