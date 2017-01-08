#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

n = int(sys.argv[1])
method = sys.argv[2]
random.seed(int(sys.argv[3]))

def gen_random(n):
    return [ random.randint(0,1) for i in range(n) ]

def gen_only0(n):
    return [0]*n
def gen_only1(n):
    return [1]*n
def gen_alternate0(n):
    res = []
    while len(res) < n:
        res.append(0)
        res.append(1)
    return res[:n]
def gen_alternate1(n):
    res = []
    while len(res) < n:
        res.append(1)
        res.append(0)
    return res[:n]

if method == 'random':
    data = gen_random(n)
elif method == 'only0':
    data = gen_only0(n)
elif method == 'only1':
    data = gen_only1(n)
elif method == 'alternate0':
    data = gen_alternate0(n)
elif method == 'alternate1':
    data = gen_alternate1(n)
else:
    assert False

print('%d' % n)
print('%s' % ' '.join(map(str, data)))
sys.stderr.write("wrote N={}\n".format(n))

