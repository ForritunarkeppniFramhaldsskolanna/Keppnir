#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

n = random.randint(0, 1000)
m = random.randint(0, 1000)

print(n)
print(m)
