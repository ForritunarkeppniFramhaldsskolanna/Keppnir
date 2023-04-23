#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

min_n = eval(sys.argv[1])
max_n = eval(sys.argv[2])
min_m = eval(sys.argv[3])
max_m = eval(sys.argv[4])

n = random.randint(min_n, max_n)
m = random.randint(min_m, max_m)

print(n)
print(m)
