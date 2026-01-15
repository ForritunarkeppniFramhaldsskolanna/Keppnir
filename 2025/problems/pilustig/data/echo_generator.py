#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])

sys.stdout.write(f"{n}\n")
