#!/usr/bin/python3
import random

random.seed(48674829)

with open("testdata.yaml", "w") as f:
    f.write("on_reject: continue\n")
    f.write("range: 0 100\n")
    f.write("grader_flags: min\n")


def write_testcase(n, adaptive=False):
    mode = 1 if adaptive else 0
    with open(f"secret/{i:03d}-{mode}.in", "w") as f:
        f.write(f"{n}\n{mode}\n")
    with open(f"secret/{i:03d}-{mode}.ans", "w") as f:
        f.write("")


for i in range(4, 51, 2):
    write_testcase(i, True)
for i in range(6, 51, 4):
    write_testcase(i, False)
