#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

exponent_min = int(sys.argv[1])
exponent_max = int(sys.argv[2])

exponent = random.randint(exponent_min, exponent_max)

number1 = random.randint(0, 10**exponent)

sys.stdout.write(f"{number1}\n")
