#!/usr/bin/env python3
s = input().strip()
for i in range(ord('a'), ord('z') + 1):
    s = s.replace(chr(i) + chr(i), chr(i))
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
