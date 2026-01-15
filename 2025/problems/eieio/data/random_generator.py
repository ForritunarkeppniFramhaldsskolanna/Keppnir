#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

has_sol = sys.argv[1] != "0"

if has_sol:
    x = random.randint(0, 150)
    y = random.randint(0, 200)
    print(x + y)
    print(4 * x + 2 * y)
else:
    print(random.randint(0, 1000))
    print(random.randint(0, 1000))
