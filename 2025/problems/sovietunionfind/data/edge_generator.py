#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

ind = int(sys.argv[1])

if ind == 0:
    print(2, 5)
    print("c", 1)
    print("c", 2)
    print("a", 1, 2)
    print("c", 1)
    print("c", 2)
if ind == 1:
    print(2, 5)
    print("c", 1)
    print("c", 2)
    print("a", 2, 1)
    print("c", 1)
    print("c", 2)
