#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

h = int(sys.argv[1])
w = int(sys.argv[2])
print(h, w)
mp = [["." for _ in range(w)] for _ in range(h)]
mp[0][0] = "G"
mp[-1][-1] = "S"
for i in range(h - 1):
    if i % 2 == 0:
        continue
    for j in range(w):
        if j == 0 and i % 4 == 3:
            continue
        if j == w - 1 and i % 4 == 1:
            continue
        mp[i][j] = "#"
for l in mp:
    print("".join(l))
