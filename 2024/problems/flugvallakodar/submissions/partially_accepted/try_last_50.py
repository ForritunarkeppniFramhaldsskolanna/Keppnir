#!/usr/bin/env python3

taken = set()

n = int(input())

for _ in range(n):
    done = False
    airport = input().strip().upper()
    for c in set(airport[2:]):
        code = (airport[0], airport[1], c)
        if code in taken:
            continue
        print("".join(code))
        taken.add(code)
        done = True
        break
    if not done:
        print(":(")

