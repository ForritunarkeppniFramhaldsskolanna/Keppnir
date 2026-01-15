#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

monotone = int(sys.argv[1])
max_x = int(sys.argv[2])
max_c = int(sys.argv[3])
min_c = 0

if len(sys.argv) >= 5:
    min_c = int(sys.argv[4])

x = random.randint(0, max_x)
a = random.randint(1, 5)
if a < 3:
    a = random.randint(1, 5)

print(a, x)

ops = ["+", "*", "/", "-"]

if monotone:
    ops = ["+", "*"]

for _ in range(a):
    op = random.choice(ops)
    c = random.randint(0, max_c)
    y = random.randint(0, 9)
    if op == "/":
        y = random.randint(1, 9)
    print(op, y, c)
