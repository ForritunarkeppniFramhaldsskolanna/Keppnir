#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
min_m = int(sys.argv[3])
max_m = int(sys.argv[4])
char_types = sys.argv[5]
assert char_types in ["all", "one"]

n = random.randint(min_n, max_n)
m = random.randint(min_m, max_m)
symbols = ".O/\\Av^" if char_types == "all" else "."

sys.stdout.write("{} {}\n".format(n, m))
for i in range(n):
    sys.stdout.write("".join([random.choice(symbols) for _ in range(m)]))
    sys.stdout.write("\n")
