#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

a = random.randint(1, 100)
b = random.randint(1, 100)
c = random.randint(720, 1439)

sys.stdout.write("{}\n{}\n{}\n".format(a, b, c))
