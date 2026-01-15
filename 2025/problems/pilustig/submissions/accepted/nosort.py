#!/usr/bin/python3
import random

throws = [(3, "Outer bullseye", 25), (4, "Bullseye", 50)]

for i in range(1, 21):
    throws.append((0, f"Single {i}", i))
    throws.append((1, f"Double {i}", i + i))
    throws.append((2, f"Triple {i}", i + i + i))


res = []

target = int(input())

for x in throws:
    if x[2] == target:
        res.append([x])
    for y in throws:
        if x[2] + y[2] == target:
            res.append([x, y])
        for z in throws:
            if x[2] + y[2] + z[2] == target:
                res.append([x, y, z])

random.seed(1337)
random.shuffle(res)
print(len(res))

for l in res:
    print(len(l))
    for x in l:
        print(x[1])
