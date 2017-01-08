#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

param = sys.argv[1]
method = sys.argv[2]
random.seed(int(sys.argv[3]))

used = set()
def random_name():
    while True:
        l = random.randint(3, 20)
        name = ''.join( random.choice(string.ascii_letters) for _ in range(l) )
        if name not in used:
            break
    used.add(name)
    return name

def gen_both(n):
    while True:
        arr = []
        for i in range(n):
            arr.append(random.choice(['Akureyri', 'Reykjavik']))
        if len(set(arr)) == 2:
            break
    res = []
    for s in arr:
        res.append(random_name())
        res.append(s)
    return res

def gen_one(n):
    use = random.choice(['Akureyri', 'Reykjavik'])
    res = []
    for i in range(n):
        res.append(random_name())
        res.append(use)
    return res

def gen_any(n,k):
    use = [ random_name() for _ in range(k) ]
    res = []
    for i in range(n):
        res.append(random_name())
        res.append(random.choice(use))
    return res


if method == 'both':
    n = int(param)
    line = gen_both(n)
elif method == 'one':
    n = int(param)
    line = gen_one(n)
elif method == 'any':
    n,k = map(int, param.split(','))
    line = gen_any(n,k)
else:
    assert False

line = ['%d' % n] + line
print('%s' % '\n'.join(line))
sys.stderr.write("wrote N={}\n".format(n))

