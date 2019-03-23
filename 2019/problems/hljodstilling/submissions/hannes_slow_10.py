#!/usr/bin/env python3
l, r, k = [int(i) for i in input().split()]

divs = [int(i) for i in input().split()]

cntr = 0
for i in range(l, r+1):
    for d in divs:
        if i % d == 0:
            cntr += 1
            continue
print(cntr)