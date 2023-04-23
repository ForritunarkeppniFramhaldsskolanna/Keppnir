#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

max_n = int(sys.argv[1])
max_d = int(sys.argv[2])
max_x = int(sys.argv[3])
setting = sys.argv[4]

if setting == "max":
    print(max_n)
    for i in range(max_n):
        print(str(max_d) + " " + " ".join([str(random.randint(max_x // 2, max_x)) for i in range(max_d)]))
    exit(0)

if max_n == 1:
    print(1)
    k = random.randint(1, max_d)
    print(str(k) + " " + " ".join([str(i + 1) for i in range(k)]))
    exit(0)

if max_n > 2:
    max_n = random.randint(max_n // 2, max_n)

print(max_n)

for i in range(max_n):
    d = random.randint(max_d // 2, max_d)
    xs = [random.randint(1, max_x) for i in range(d)]
    print(str(d) + " " + " ".join([str(x) for x in xs]))

