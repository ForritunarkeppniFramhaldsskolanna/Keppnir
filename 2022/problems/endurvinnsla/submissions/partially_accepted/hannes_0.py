#!/usr/bin/env python3

import sys

city_name = sys.stdin.readline().strip()
percentage = float(sys.stdin.readline().strip())
n = int(sys.stdin.readline().strip())
plastics = 0
non_plastics = 0

for _ in range(n):
    line = sys.stdin.readline().strip()
    if line == "plast":
        plastics += 1
    else:
        non_plastics += 1
if (non_plastics / (plastics + non_plastics)) >= percentage:
    print("Neibb")
else:
    print("Jebb")
