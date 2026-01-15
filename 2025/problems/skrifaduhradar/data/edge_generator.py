#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

typ = sys.argv[1]

if typ == "maxans":
    n = int(sys.argv[2])
    s = int(sys.argv[3])
    print(n, 1)
    w = [s for _ in range(n)]
    print(" ".join([str(x) for x in w]))
