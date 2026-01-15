#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "zero1":
    print(1)
    print(1, 1, 0)

if typ == "zero2":
    print(100)
    for _ in range(100):
        a = random.randint(0, 10**9)
        print(a, a, 0)

if typ == "max1":
    print(1)
    a = random.randint(0, 10**9)
    print(a, a, 10**9)

if typ == "max2":
    print(10**5)
    a = random.randint(0, 10**9)
    for _ in range(10**5):
        print(a, a, 10**9)

if typ == "max3":
    print(10**2)
    a = random.randint(0, 10**9)
    for _ in range(10**2):
        print(a, a, 10**2)

if typ == "heapstress":
    print(10**5)
    for _ in range(10**5):
        a = random.randint(0, 10**4)
        b = random.randint(10**4 + 1, 2 * 10**4)
        t = random.randint(0, 10**9)
        print(a, b, t)

if typ == "empty":
    print(0)
