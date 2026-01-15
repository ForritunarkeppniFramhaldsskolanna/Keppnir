#!/usr/bin/python3
import sys
import random


def f():
    return random.randint(0, 255)


random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "diff":
    x, y, z = f(), f(), f()
    while len(set([x, y, z])) < 3:
        x, y, z = f(), f(), f()
    print(x, y, z)

if typ == "eq12":
    x, z = f(), f()
    while x <= z:
        x, z = f(), f()
    print(x, x, z)

if typ == "eq13":
    x, y = f(), f()
    while x <= y:
        x, y = f(), f()
    print(x, y, x)

if typ == "eq23":
    x, y = f(), f()
    while x >= y:
        x, y = f(), f()
    print(x, y, y)

if typ == "eq123":
    x = f()
    while x in [0, 255]:
        x = f()
    print(x, x, x)

if typ == "black":
    print(0, 0, 0)

if typ == "white":
    print(255, 255, 255)

if typ == "rand":
    x, y, z = f(), f(), f()
    print(x, y, z)
