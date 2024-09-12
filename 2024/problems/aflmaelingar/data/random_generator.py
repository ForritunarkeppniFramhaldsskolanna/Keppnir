#!/usr/bin/python3
import sys, random, math

random.seed(int(sys.argv[-1]))

k = int(sys.argv[1])
q = int(sys.argv[2])

print(k, q)

vals = []
for i in range(300):
    vals.append(random.randint(0, 99))

print(" ".join([str(x) for x in vals]))
