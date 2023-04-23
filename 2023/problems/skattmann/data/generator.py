#!/usr/bin/env python3
import json
import random

random.seed(1337)

def write_testcase(i, entry):
    with open('secret/{:02d}.in'.format(i), 'w') as f:
        f.write(str(entry["n"]) + "\n")
    with open('secret/{:02d}.ans'.format(i), 'w') as f:
        f.write(str(len(entry["moves"])) + "\n")
        mov = [str(x) for x in entry["moves"]]
        f.write(' '.join(mov) + "\n")

k1data = []
k10data = []

with open('1k.json', 'r') as f:
    k1data = json.load(f)

with open('10k.json', 'r') as f:
    k10data = json.load(f)

# 4 <= n <= 1000 (50%)
# For n <= 1000 generating the optimal solution is feasible
# so 1k.json has the optimal solution for all n <= 1000

done = set()

for i in range(50):
    n = random.randint(4, 1000)
    # 7, 13 are tricky so make sure they are included
    if i == 0: n = 7
    if i == 1: n = 13
    while n in done:
        n = random.randint(4, 1000)
    done.add(n)
    entry = k1data[n - 1]
    assert entry["n"] == n
    write_testcase(i, entry)

# 1000 < n <= 10000 (50%)
# Here getting the optimal solution is not as feasible, and
# 10k.json is the result of running a heuristic solution for
# 50 random values in this range. 

for i in range(50):
    entry = k10data[i]
    write_testcase(i + 50, entry)

