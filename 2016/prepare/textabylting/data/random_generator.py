#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

n = int(sys.argv[1])
l = int(sys.argv[2])
same = sys.argv[3] == 'True'
random.seed(int(sys.argv[4]))

print(n)

def gen_str(l):
    s = ''
    while len(s) < l:
        here = string.ascii_letters + string.digits
        if len(s) > 0 and len(s)+1 < l and s[-1] != ' ':
            here += ' '*(len(here)//8)
        s += random.choice(here)
    return s

for i in range(n):
    curl = l if same else random.randint(1, l)
    print(gen_str(curl))

