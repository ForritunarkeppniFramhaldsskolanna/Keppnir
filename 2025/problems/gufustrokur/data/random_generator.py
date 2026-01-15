#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

number1 = random.randint(0, 359)
number2 = random.randint(0, 359)

sys.stdout.write(f"{number1}\n")
sys.stdout.write(f"{number2}\n")
