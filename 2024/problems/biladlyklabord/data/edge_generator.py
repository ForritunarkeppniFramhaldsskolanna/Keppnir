#!/usr/bin/python3
import random
import sys
import string

n = eval(sys.argv[1])
typ = sys.argv[2]

if typ == "repeat":
    print(random.choice(string.ascii_lowercase) * (n - 1))

if typ == "check_cyc":
    print("aba")
