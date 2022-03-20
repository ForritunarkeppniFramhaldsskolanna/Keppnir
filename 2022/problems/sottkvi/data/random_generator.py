#!/usr/bin/python3

import sys
import random

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
max_k = eval(sys.argv[2])
max_d = eval(sys.argv[3])

n = max_n
k = max_k
d = random.randint(1, max_d)

print(n, k, d)

for i in range(n):
    print(random.randint(max(d-14, 1), d))
