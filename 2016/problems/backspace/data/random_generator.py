#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

n = int(sys.argv[1])
alpha = int(sys.argv[2])
method = sys.argv[3]
random.seed(int(sys.argv[4]))

alpha = string.ascii_lowercase[:alpha]

def gen_random(n,alpha):
    res = []
    left = 0
    for i in range(n):
        if left > 0 and random.randint(0,5) == 0:
            res.append('<')
            left -= 1
        else:
            res.append(random.choice(alpha))
            left += 1
    return ''.join(res)

def gen_erase(n, alpha):
    a = (n+1)//2
    b = n-a
    return ''.join([ random.choice(alpha) for _ in range(a) ]) + '<' * b

def gen_interleave(n, alpha):
    return ''.join([ '<' if i % 2 != 0 else random.choice(alpha) for i in range(n) ])

def gen_interleave2(n, alpha):
    res = []
    while len(res) < n:
        for _ in range(random.randint(1,8)):
            res.append(random.choice(alpha))
        res.append('<')
    return ''.join(res[:n])

def gen_blocks(n, alpha):
    res = []
    while len(res) < n:
        add = random.randint(1,8)
        for _ in range(add):
            res.append(random.choice(alpha))
        sub = random.randint(1,add)
        for _ in range(sub):
            res.append('<')
    return ''.join(res[:n])

def gen_worst(n, alpha):
    res = []
    m = int(math.sqrt(n))
    while len(res) < n:
        for _ in range(m):
            res.append(random.choice(alpha))
        res.append('<')
    return ''.join(res[:n])
def gen_none(n, alpha):
    res = []
    while len(res) < n:
        res.append(random.choice(alpha))
    return ''.join(res[:n])

if method == 'random':
    line = gen_random(n,alpha)
elif method == 'erase':
    line = gen_erase(n,alpha)
elif method == 'interleave':
    line = gen_interleave(n,alpha)
elif method == 'interleave2':
    line = gen_interleave2(n,alpha)
elif method == 'blocks':
    line = gen_blocks(n,alpha)
elif method == 'worst':
    line = gen_worst(n,alpha)
elif method == 'none':
    line = gen_none(n,alpha)
else:
    assert False

print('%s' % line)
sys.stderr.write("wrote N={}\n".format(len(line)))

