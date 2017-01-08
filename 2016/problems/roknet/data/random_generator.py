#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

n = int(sys.argv[1])
io = sys.argv[2] == 'True'
qs = int(sys.argv[3])
random.seed(int(sys.argv[4]))

data = set()
def gen_name():
    while True:
        l = random.randint(1,7)
        here = ''.join( random.choice(string.digits + string.ascii_lowercase) for _  in range(l) )
        if here in data:
            continue
        return here

print('%d' % n)
for i in range(n):
    choices = set([ 'INNTAK' ])
    if data:
        choices |= set([ 'UTTAK' ])
        if not io:
            choices |= set([ 'OG', 'EDA', 'EKKI' ])

    op = random.choice(list(choices))
    if op == 'INNTAK':
        name = gen_name()
        data.add(name)
        val = random.choice([ 'SATT', 'OSATT' ])
        if qs > 0 and random.randint(0,1) == 1:
            qs -= 1
            val = '?'
        print('%s %s %s' % (op, name, val))
    elif op == 'UTTAK':
        print('%s %s' % (op, random.choice(list(data))))
    elif op == 'OG' or op == 'EDA':
        a = random.choice(list(data))
        b = random.choice(list(data))
        c = gen_name()
        data.add(c)
        print('%s %s %s %s' % (op, a, b, c))
    elif op == 'EKKI':
        a = random.choice(list(data))
        c = gen_name()
        data.add(c)
        print('%s %s %s' % (op, a, c))
    else:
        assert False

