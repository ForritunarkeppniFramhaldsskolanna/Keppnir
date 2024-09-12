#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

min_n = eval(sys.argv[1].lstrip('0'))
max_n = eval(sys.argv[2].lstrip('0'))

sys.stdout.write(f"{random.randint(min_n, max_n)}\n")
