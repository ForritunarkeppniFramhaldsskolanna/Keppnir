#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

mode = sys.argv[1]
if mode == "random":
    w = [int(sys.argv[i]) for i in range(2, 6)]
    n = int(eval(sys.argv[6]))
    m = int(eval(sys.argv[7]))
else:
    w = [25 for i in range(2, 6)]
    n = int(eval(sys.argv[2]))
    m = int(eval(sys.argv[3]))

cs = ['P', 'I', 'Z', 'A']
pizzastring = "".join(random.choices(cs, weights=w, k=n))
print(mode)
print(n, m)
print(pizzastring)
