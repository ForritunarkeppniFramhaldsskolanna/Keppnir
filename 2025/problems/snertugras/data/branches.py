#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

h = int(sys.argv[1])
w = int(sys.argv[2])
print(h, w)
mp = [["." for _ in range(w)] for _ in range(h)]
mp[0][0] = "S"
for i in range(1, h):
    for j in range(w):
        if j % 2 == 1:
            mp[i][j] = "#"
x = random.randint(0, w - 1)
while x % 2 == 1:
    x = random.randint(0, w - 1)
mp[-1][x] = "G"
for l in mp:
    print("".join(l))
