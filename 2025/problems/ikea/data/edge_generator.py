#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "ORD":
    print(2)
    print(10)

    print("ZUCK", 10)
    print("LUCK", 10)
    print("CHAIR", 10)
    print("HAHA", 10)
    print("ROOT", 10)
    print("ZZZZ", 9)
    print("ABCDEF", 10)
    print("A", 10)
    print("B", 10)
    print("AA", 10)

if typ == "CEIL":
    print(3)
    print(5)

    print("ABC", 1)
    print("ABD", 2)
    print("ABE", 4)
    print("ABF", 4)
    print("ABG", 5)

if typ == "FLOOR":
    print(3)
    print(5)

    print("ABC", 1)
    print("ABD", 2)
    print("ABE", 3)
    print("ABF", 4)
    print("ABG", 5)
