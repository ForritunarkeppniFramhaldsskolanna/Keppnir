#!/usr/bin/python3
import sys, random, math

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "zero":
    print(1)
    print("a", 0, 0)

if typ == "zero2":
    print(3)
    print("c", 0, 0)
    print("a", 0, 0)
    print("b", 0, 0)
