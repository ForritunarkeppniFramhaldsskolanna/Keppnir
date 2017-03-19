#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

n = eval(sys.argv[1]) # vars
m = eval(sys.argv[2]) # clauses
random.seed(int(sys.argv[3]))

allvs = [ chr(ord('a') + i) for i in range(26) ] + [ chr(ord('a') + i) + chr(ord('a') + j) + chr(ord('a') + k) for i in range(26) for j in range(26) for k in range(26) ]
vs = allvs[:n]

cls = []
for _ in range(n-1):
    use = random.randint(1,n)
    random.shuffle(vs)
    use = vs[:use]
    spec = random.choice(vs)
    cls.append([ random.choice(['', '!']) + v for v in use ] + [ spec, '!' + spec ])

for i in range(len(cls)):
    random.shuffle(cls[i])
random.shuffle(cls)

res = ' EDA '.join( '(' + ' OG '.join(c) + ')' for c in cls )

print(res)

