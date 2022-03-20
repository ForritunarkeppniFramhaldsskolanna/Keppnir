#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

n = eval(sys.argv[1])
m = eval(sys.argv[2])
spec = eval(sys.argv[3])

def get_tup():
    x = random.randint(-10**8,10**8)
    y = random.randint(-10**8,10**8)
    z = random.randint(-10**8,10**8)
    return (x, y, z)

def print_random_edge(shf, corr):
    a = random.randint(1, n)
    b = random.randint(1, n)
    if (not corr) and (spec == 1):
        b = a
    x = shf[a - 1][0] - shf[b - 1][0]
    y = shf[a - 1][1] - shf[b - 1][1]
    z = shf[a - 1][2] - shf[b - 1][2]
    if not corr:
        t = random.randint(1, 6)
        if t == 1: x += 1
        elif t == 2: x -= 1
        elif t == 3: y += 1
        elif t == 4: y -= 1
        elif t == 5: z += 1
        else: z -= 1
    print(a, b, x, y, z)

shf = [get_tup() for i in range(n)]

print(n, m)

for i in range(m - 1):
    print_random_edge(shf, True)

print_random_edge(shf, random.randint(1, 2) == 1)
