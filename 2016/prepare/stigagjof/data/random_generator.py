#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

n = int(sys.argv[1])
k = int(sys.argv[2])
random.seed(int(sys.argv[3]))

names = ['test1meow',
        'test2',
        'test3moo',
        'test4',
        'test5']

random.shuffle(names)
print(names[0])
print(k)

subs = [ (random.randint(1,360), random.choice(names[:n]), random.randint(0, 100)) for _ in range(k) ]
subs = sorted(subs, key = lambda x: x[0])

for (t, s, n) in subs:
    print('%d %s %d' % (t,s,n))

