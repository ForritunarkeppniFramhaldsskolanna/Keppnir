#!/usr/bin/env python3
import random

random.seed(13337)

def write_testcase(i, n, arr):
    with open(f"secret/{i:02d}.in", 'w') as f:
        f.write(f"{n}\n")
        f.write(" ".join(map(str, arr)))
        f.write("\n")
    with open(f"secret/{i:02d}.ans", 'w') as f:
        pass

n = 10**4
arr = [i+1 for i in range(n)]

for i in range(20):
    random.shuffle(arr)
    write_testcase(i, n, arr)
