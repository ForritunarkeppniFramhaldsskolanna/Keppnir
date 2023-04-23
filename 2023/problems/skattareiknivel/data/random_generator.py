#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

print("{:.2f}".format(random.uniform(0, 4)))
print("{:.2f}".format(random.uniform(0, 4)))

for i in range(12):
    print(random.randint(0, 10**8))
