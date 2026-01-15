#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

a = random.randint(0, 10**9)
b = random.randint(0, 10**9)

print("0x{:x} + 0x{:x}".format(a, b))
