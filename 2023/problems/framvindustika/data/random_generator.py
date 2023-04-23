#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

min_p = int(sys.argv[1])
max_p = int(sys.argv[2])
min_w = int(sys.argv[3])
max_w = int(sys.argv[4])

p = random.randint(min_p, max_p)
w = random.randint(min_w, max_w)

print("{} {}".format(p, w))
