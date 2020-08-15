#!/usr/bin/env python3
import sys

a = input()
b = input()

if a == b:
    print(1)
    sys.exit(0)

diff_count = 0

for i in range(len(a)):
    if a[i] != b[i]:
        diff_count += 1

print(diff_count + 1)
