#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

max_h = eval(sys.argv[1])
max_w = eval(sys.argv[2])
max_d = eval(sys.argv[3])

group = sys.argv[4]

min_h, min_w, min_d = max_h, max_w, max_d

if group != "A":
    prvs = []
    if group == "B":
        prvs = [0, 1, 2, 4, 8]
    if group == "C":
        prvs = [0, 1, 2, 3, 100]
    if group == "D":
        prvs = [0, 1, 2, 5, 100]
    min_h = prvs[prvs.index(max_h) - 1] + 1
    min_w = prvs[prvs.index(max_w) - 1] + 1
    min_d = prvs[prvs.index(max_d) - 1] + 1

h = random.randint(min_h, max_h)
w = random.randint(min_w, max_w)
d = random.randint(min_d, max_d)

if group != "A" and max(h, w, d) <= 3:
    h = random.randint(min_h, max_h)
    w = random.randint(min_w, max_w)
    d = random.randint(min_d, max_d)

print(h, w, d)
