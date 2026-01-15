#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])

number1 = random.randint(min_n, max_n)
number2 = random.randint(min_n, max_n)

sys.stdout.write(f"{number1} ? {number2}\n")
