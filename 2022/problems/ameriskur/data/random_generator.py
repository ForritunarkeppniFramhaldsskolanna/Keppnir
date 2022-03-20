#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])

print(random.randint(1, max_n))
