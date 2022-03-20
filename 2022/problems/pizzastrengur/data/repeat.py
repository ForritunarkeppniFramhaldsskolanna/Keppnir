#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

seq = sys.argv[1]
n = int(eval(sys.argv[2]))
m = int(eval(sys.argv[3]))

pizzastring = seq * (n // len(seq) + 1)
print("random")
print(n, m)
print(pizzastring[:n])
