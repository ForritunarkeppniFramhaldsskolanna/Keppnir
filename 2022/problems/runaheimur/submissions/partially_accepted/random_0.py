#!/bin/python3
import random
n = random.randint(0, 50)
for _ in range(n):
    print(random.choice("UDLR"), end="")
print()
