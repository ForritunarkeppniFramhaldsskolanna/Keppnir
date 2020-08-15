#!/usr/env/bin python3
import sys
b = []

for c in input().strip():
    if c == '.':
        continue
    if c.lower() == c:
        b.append(c)
    else:
        while True:
            if len(b) == 0:
                print("Neibb")
                sys.exit(0)
            if b[-1] == c.lower():
                b.pop()
                break
            b.pop()

print(b.count('p'))
print(b.count('g'))
print(b.count('o'))

