#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys

S = sys.argv[1]
K = int(sys.argv[2])
method = sys.argv[3]
random.seed(int(sys.argv[4]))

def gen_from_cyc(cyc):
    cycs = []
    for part in cyc.split(','):
        if 'x' in part:
            mul,sz = part.split('x')
        else:
            mul = 1
            sz = part
        mul = int(mul)
        sz = int(sz)
        for i in range(mul):
            cycs.append(sz)
    n = sum(cycs)
    perm = [-1] * sum(cycs)
    labels = list(range(1,n+1))
    at = 0
    for c in cycs:
        cur = labels[at:at+c]
        at += c
        for i in range(len(cur)):
            perm[cur[i]-1] = cur[(i+1)%len(cur)]
    return perm

def gen_random(n):
    res = list(range(1,n+1))
    random.shuffle(res)
    return res

if method == 'cyc':
    perm = gen_from_cyc(S)
else:
    perm = gen_random(int(S))

lines = ['%d %d' % (len(perm), K)]
lines += [ ' '.join(map(str,perm)) ]

print('\n'.join(lines))
sys.stderr.write("wrote N={}, K={}\n".format(len(perm), K))

