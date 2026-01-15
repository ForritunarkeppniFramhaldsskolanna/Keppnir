#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "plain":
    print(1, 1)
    print("S")

if typ == "adj1":
    print(1, 2)
    print("SG")

if typ == "adj2":
    print(2, 1)
    print("G")
    print("S")

if typ == "se2":
    print(2, 1)
    print("S")
    print(".")

if typ == "block1":
    print(2, 2)
    print("G#")
    print("#S")

if typ == "block2":
    print(2, 2)
    print("#S")
    print("G#")

if typ == "emptyblock":
    print(2, 2)
    print(".S")
    print("..")

if typ == "dist2":
    print(2, 2)
    print(".G")
    print("S.")
