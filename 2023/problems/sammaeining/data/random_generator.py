#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

minN = int(sys.argv[1])
maxN = int(sys.argv[2])
prop = int(sys.argv[3])

n = random.randrange(minN, maxN + 1)
if prop == 10:
    n -= n % 10

sys.stdout.write("{}\n".format(n))
