#!/usr/bin/python3
import sys
import random

MN = 0
MX = 10**9
gen_type = sys.argv[1]
random.seed(int(sys.argv[-1]))

a,b,c = 0, 0, 0
if gen_type == "random":
    s = set()
    while len(s) < 3:
        s.add(random.randint(MN, MX))
    L = list(s)
    random.shuffle(L)
    a,b,c = L
elif gen_type == "lex":
    a = 19
    b = 154
    c = 1510
elif gen_type == "close":
    L = [random.randint(MN, MX-2)]
    L.append(L[0]+1)
    L.append(L[0]+2)
    random.shuffle(L)
    a,b,c = L

sys.stdout.write("{}\n{}\n{}\n".format(a, b, c))
