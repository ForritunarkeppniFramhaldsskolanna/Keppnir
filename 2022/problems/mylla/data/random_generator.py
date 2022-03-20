#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

filename = sys.argv[1]
ind = int(sys.argv[2])-1

state = None
with open(filename, "r") as f:
    states = f.readlines()
    state = states[ind].strip()

for i in range(9):
    print(state[i], end='')
    if i%3 == 2:
        print()
