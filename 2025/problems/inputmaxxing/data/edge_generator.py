#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "equal":
    print(2)
    print(10)
    print(10)

if typ == "nmax":
    print(11)
    for i in range(11):
        print(10)
