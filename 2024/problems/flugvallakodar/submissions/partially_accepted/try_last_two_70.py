#!/usr/bin/env python3

taken = set()

n = int(input())

for _ in range(n):
    done = False
    airport = input().strip().upper()
    for j in range(1, len(airport)):
        for c in set(airport[j + 1:]):
            code = (airport[0], airport[j], c)
            if code in taken:
                continue
            print("".join(code))
            taken.add(code)
            done = True
            break
        if done:
            break
    if not done:
        print(":(")

