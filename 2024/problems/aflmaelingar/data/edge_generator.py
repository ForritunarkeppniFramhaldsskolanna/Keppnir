#!/usr/bin/python3
import sys, random, math

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]
k = int(sys.argv[2])
q = int(sys.argv[3])

print(k, q)

vals = []
for i in range(300):
    if typ == "min":
        vals.append(0)
    if typ == "max":
        vals.append(99)

print(" ".join([str(x) for x in vals]))
