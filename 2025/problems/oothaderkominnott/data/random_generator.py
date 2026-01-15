#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

i = int(sys.argv[1])
min_n = int(sys.argv[2])
max_n = int(sys.argv[3])

n = random.randint(min_n, max_n)
m = random.randint(min_n, max_n)
h = random.randint(min_n, max_n)

if i == 1:
    print(1)
    print(n)

elif i == 2:
    print(2)
    print(n)
    print(m)

elif i == 3:
    print(3)
    print(n)
    print(m)
    print(h)
