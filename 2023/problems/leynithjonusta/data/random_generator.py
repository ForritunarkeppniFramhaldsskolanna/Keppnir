#!/usr/bin/python3
import sys
import random
from string import ascii_lowercase

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
special = sys.argv[3]

n = random.randint(min_n, max_n)

s = ""
if special == "special":
    x = (n-6)//4
    y = x + (n-6)%4
    s = "a{}@{}b{}.{}c".format(" "*y, " "*x, " "*x, " "*x)
else:
    L = []
    while "@" not in L:
        L = []
        SYMS = ascii_lowercase
        for i in range(n):
            if i == n-1:
                SYMS = SYMS.replace(" ", "")
            sym = random.choice(SYMS)
            L.append(sym)
            if i == 0:
                SYMS += " .@"
            elif sym == "@":
                SYMS = SYMS.replace("@", "")
        s = ''.join(L)
        
sys.stdout.write("{}\n".format(s))
