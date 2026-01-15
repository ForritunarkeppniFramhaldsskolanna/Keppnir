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
for i in range(h):
    for j in range(w):
        if mp[i][j] != ".":
            continue
        if i % 2 == 1 and j % 2 == 1:
            mp[i][j] = "#"
for l in mp:
    print("".join(l))
