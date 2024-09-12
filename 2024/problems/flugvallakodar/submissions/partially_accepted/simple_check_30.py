#!/usr/bin/env python3

n = int(input())
taken = set()
for _ in range(n):
    nam = input().strip().upper()[:3]
    if nam in taken:
        print(":(")
    else:
        print(nam)
        taken.add(nam)
