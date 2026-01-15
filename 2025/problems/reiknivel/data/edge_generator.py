#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "badbfs":
    max_x = int(sys.argv[2])
    print("2", max_x)
    print("+ 3 2")
    print("+ 2 1")

if typ == "badbfs2":
    max_x = int(sys.argv[2])
    print("2", max_x)
    print("+ 3 1")
    print("+ 2 0")

if typ == "badminus":
    print("3", 10**8 - 1)
    print("+ 3 2")
    print("+ 2 1")
    print("- 2 3")

if typ == "maxB":
    print(5, 10**8 - 1)
    print("+ 3 2")
    print("+ 2 1")
    print("+ 1 3")
    print("* 1 3")
    print("* 0 1")

if typ == "weirdops":
    print(4, 1000)
    print("* 1 0")
    print("* 0 0")
    print("+ 0 0")
    print("+ 4 3")

if typ == "maxC":
    print(5, 10**8 - 1)
    print("+ 3 1")
    print("- 2 1")
    print("/ 1 0")
    print("* 1 0")
    print("* 0 0")

if typ == "weirdops2":
    print(4, 10**8 - 1)
    print("/ 1 0")
    print("* 0 0")
    print("+ 0 0")
    print("+ 4 1")

if typ == "zero1":
    print(3, 0)
    print("+ 0 1")
    print("* 0 0")
    print("* 1 1")

if typ == "zero2":
    print(3, 0)
    print("+ 2 1")
    print("* 3 0")
    print("+ 1 1")

if typ == "dkstrB":
    print(5, 10**8 - 1)
    print("+ 1 0")
    print("+ 2 1")
    print("+ 3 2")
    print("+ 4 3")
    print("+ 0 0")

if typ == "dkstrC":
    print(5, 10**8 - 1)
    print("+ 1 0")
    print("+ 2 1")
    print("+ 3 1")
    print("+ 4 1")
    print("- 1 1")

if typ == "dkstrD":
    print(5, 10**8 - 1)
    print("+ 1 0")
    print("+ 2 1")
    print("+ 3 2")
    print("+ 4 3")
    print("- 1 1")

if typ == "maxbreak":
    print(4, 10**8 - 1)
    print("+ 5 1")
    print("* 2 0")
    print("* 5 0")
    print("- 1 1")
