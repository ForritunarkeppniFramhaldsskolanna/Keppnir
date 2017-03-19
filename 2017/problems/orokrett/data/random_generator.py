#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

mn_clauses = eval(sys.argv[1])
mx_clauses = eval(sys.argv[2])
mn_vsperclause = eval(sys.argv[3])
mx_vsperclause = eval(sys.argv[4])
mn_vars = eval(sys.argv[5])
mx_vars = eval(sys.argv[6])

random.seed(int(sys.argv[7]))

allvs = [ chr(ord('a') + i) for i in range(26) ] + [ chr(ord('a') + i) + chr(ord('a') + j) + chr(ord('a') + k) for i in range(26) for j in range(26) for k in range(26) ]
vs = allvs[:random.randint(mn_vars, mx_vars)]

res = ' EDA '.join( '(' + ' OG '.join( random.choice(['','!']) + random.choice(vs) for v in range(random.randint(mn_vsperclause, mx_vsperclause)) ) + ')' for c in range(random.randint(mn_clauses, mx_clauses)) )

print(res)

