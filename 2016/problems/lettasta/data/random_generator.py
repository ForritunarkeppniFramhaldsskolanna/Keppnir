#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

n = int(sys.argv[1])
m = int(sys.argv[2])
random.seed(int(sys.argv[3]))

print(n)
print(m)

names = [
    'banani',
    'epli',
    'meow',
    'moo',
    'agurka',
    'eggert',
    'ekkert',
    'nafn',
    'annadnafn',
    'veitekkilengur',
    'x',
    'y',
]

random.shuffle(names)
print(' '.join(names[:n]))

while True:
    arr = [ [ random.randint(0,100) for j in range(n) ] for i in range(m) ]
    sm = [0]*n
    for i in range(m):
        for j in range(n):
            sm[j] += arr[i][j]

    sm = sorted(sm)
    if n == 1 or sm[-1] != sm[-2]:
        break

for i in range(m):
    print(' '.join(map(str,arr[i])))

