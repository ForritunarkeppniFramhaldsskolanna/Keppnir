#!/usr/bin/env python3
s = list(input().strip())
while True:
    done = True
    for i in range(len(s)):
        if s[i] == s[i - 1]:
            del s[i]
            done = False
            break
    if done:
        break
print("".join(s))
