#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

min_m = int(sys.argv[1])
min_n = int(sys.argv[2])
max_m = int(sys.argv[3])
max_n = int(sys.argv[4])
assert min_m <= max_m
assert min_n <= max_n
congestion_ratio = float(sys.argv[5])

m = random.randint(min_m, max_m)
n = random.randint(min_n, max_n)

print(m)
print(n)

for lanes in range(n):
    for spot in range(m):
        random_sample = random.uniform(0, 1)
        if random_sample <= congestion_ratio:
            sys.stdout.write("#")
            #print("#", )
        else:
            sys.stdout.write(".")
            # print(".")
    sys.stdout.write("\n")