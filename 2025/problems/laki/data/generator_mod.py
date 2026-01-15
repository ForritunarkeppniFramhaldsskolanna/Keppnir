#!/usr/bin/python3
import sys
import random
import math

random.seed(int(sys.argv[-1]))

a = random.randint(2, 10**3)
b = random.randint(2, 10**3)

while math.gcd(a, b) > 1:
    a = random.randint(2, 10**3)
    b = random.randint(2, 10**3)

x = random.randint(0, a - 1)
y = random.randint(0, b - 1)

print("{} mod {} + {} mod {}".format(x, a, y, b))
