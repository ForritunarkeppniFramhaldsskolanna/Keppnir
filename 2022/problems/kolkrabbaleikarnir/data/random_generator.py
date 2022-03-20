#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

MIN_N = int(sys.argv[1])
MAX_N = int(sys.argv[2])
MIN_M = int(sys.argv[3])
MAX_M = int(sys.argv[4])

print(random.randint(MIN_N, MAX_N), random.randint(MIN_M, MAX_M))
