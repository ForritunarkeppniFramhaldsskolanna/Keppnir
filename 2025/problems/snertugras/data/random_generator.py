#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

max_h = int(sys.argv[1])
max_w = int(sys.argv[2])
max_n = int(sys.argv[3])
allow_wall = int(sys.argv[4])
density = int(sys.argv[5])

h, w = random.randint(1, max_h), random.randint(1, max_w)
while h * w > max_n:
    h, w = random.randint(1, max_h), random.randint(1, max_w)
print(h, w)
mp = [["." for _ in range(w)] for _ in range(h)]
x = random.randint(0, h - 1)
y = random.randint(0, w - 1)
mp[x][y] = "S"
obst = x * y * 20 // 100
for _ in range(obst):
    x = random.randint(0, h - 1)
    y = random.randint(0, w - 1)
    if mp[x][y] == "S":
        continue
    if random.randint(1, 3) == 1 or not allow_wall:
        mp[x][y] = "G"
    else:
        mp[x][y] = "#"
for l in mp:
    print("".join(l))
