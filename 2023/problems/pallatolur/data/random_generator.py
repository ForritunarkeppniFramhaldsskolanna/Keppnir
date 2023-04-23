#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

tp = sys.argv[1]

if tp == "sad":
    if random.randint(0, 1) == 0:
        a = random.randint(-10**9, 1)
        b = random.randint(a, -1)
    else:
        a = random.randint(3, 10**9)
        b = random.randint(a, 10**9)
elif tp == "fixed":
    a = eval(sys.argv[2])
    b = eval(sys.argv[3])
else:
    a = 2 - random.randint(0, 10**9 + 2)
    b = 2 + random.randint(0, 10**9 - 2)

print(a)
print(b)
