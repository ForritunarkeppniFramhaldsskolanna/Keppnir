#!/usr/bin/python3
import random
import sys

random.seed(48674829)

with open("sample/testdata.yaml", "w") as f:
    f.write("on_reject: continue\n")
    f.write("range: 0 2\n")
    f.write("grader_flags: sum accept_if_any_accepted\n")

with open("testdata.yaml", "w") as f:
    f.write("on_reject: continue\n")
    f.write("range: 0 100\n")
    f.write("grader_flags: ignore_sample\n")

with open("secret/testdata.yaml", "w") as f:
    f.write("on_reject: continue\n")
    f.write("range: 0 100\n")
    f.write("grader_flags: sum accept_if_any_accepted\n")


def write_testcase(n, agent):
    seed = random.randint(0, 4294967295)
    sys.stderr.write(f"Generating testcase secret/{n:02d}-{agent}\n")
    with open(f"secret/{n:02d}-{agent}.in", "w") as f:
        f.write(f"{agent} {seed}\n")
    with open(f"secret/{n:02d}-{agent}.ans", "w") as f:
        pass


for agent in ["worst", "random", "rand2", "half", "best"]:
    for i in range(1, 11):
        write_testcase(i, agent)
