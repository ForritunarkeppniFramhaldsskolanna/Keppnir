#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])

sys.stdout.write(f"{random.randint(min_n, max_n)}\n")
