#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

method = sys.argv[1]
mx = int(sys.argv[2])
random.seed(int(sys.argv[3]))

n = random.randint(1,mx)

if method == 'whatevs':
    a = random.randint(1, n)
    b = random.randint(1, n)
    if a > b:
        a, b = b,a
else:
    a = 1
    b = random.randint(1, n)

print(n)
print('%d %d' % (a, b))
