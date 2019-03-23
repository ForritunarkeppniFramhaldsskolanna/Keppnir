#!/usr/bin/env python3
n, r, c = [int(i) for i in input().split()]
rows = []
roll_call = []

inverted = []

for i in range(r):
    rows.extend(input().split())

for i in range(n):
    roll_call.append(input())


for i in range(0, n, c):
    inverted.append(rows[i] == roll_call[i])


for i in inverted:
    if i:
        print("left")
    else:
        print("right")