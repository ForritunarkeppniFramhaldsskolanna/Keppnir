#!/usr/bin/python3

import sys

import random

random.seed(int(sys.argv[-1]))

min_n = eval(sys.argv[1])
max_n = eval(sys.argv[2])
min_k = eval(sys.argv[3])
max_k = eval(sys.argv[4])

n = random.randint(min_n, max_n)
k = random.randint(min_k, max_k)

print(n, k)
