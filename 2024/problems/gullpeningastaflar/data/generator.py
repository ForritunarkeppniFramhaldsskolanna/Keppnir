#!/usr/bin/python3
import sys
import random

random.seed(48674829)

def write_testcase(i, n, adaptive=False):
    fake_index = 0 if adaptive else random.randint(1, n)
    with open(f"secret/{i:03d}.in", 'w') as f:
        f.write(f"{n} {fake_index}\n")
    with open(f"secret/{i:03d}.ans", 'w') as f:
        f.write(f"{fake_index}\n")

for i in range(1, 20):
    write_testcase(i, 1024, False)
write_testcase(21, 1024, True)
