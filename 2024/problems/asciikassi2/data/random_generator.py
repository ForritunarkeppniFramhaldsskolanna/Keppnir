#!/usr/bin/python3
import sys, random

random.seed(int(sys.argv[-1]))

min_n = eval(sys.argv[1])
max_n = eval(sys.argv[2])

print(random.randint(min_n, max_n))

