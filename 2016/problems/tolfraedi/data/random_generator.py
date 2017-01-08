#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string


lines = []

Q = int(sys.argv[1])
maxX = int(sys.argv[2])
method = sys.argv[3]
if method == 'wremove':
    removeratio = float(sys.argv[4])
    sys.stderr.write("{} {} {}\n".format(Q, maxX, method))
else:
    sys.stderr.write("{} {}\n".format(Q, maxX))

random.seed(int(sys.argv[-1]))


def noremove():
    for i in range(Q):
        n = random.randint(0,maxX)
        lines.append("A {}".format(n))

def wremove():
    theset = {}
    for i in range(Q):
        if len(theset):
            if random.random() > removeratio:
                n = random.randint(1,maxX)
                if n in theset.keys():
                    theset[n] += 1
                else:
                    theset[n] = 1
                lines.append("A {}".format(n))
            else:
                n = random.choice(list(theset.keys()))
                if theset[n] == 1:
                    del theset[n]
                else:
                    theset[n] -= 1
                lines.append("R {}".format(n))

        else:
            n = random.randint(1,maxX)
            theset[n] = 1
            lines.append("A {}".format(n))

def add_then_remove_all():
    added = []
    for i in range(Q//2):
        n = random.randint(1,maxX)
        added.append(n)
        lines.append("A {}".format(n))
    for j in added:
        lines.append("R {}".format(j))
    if Q % 2 == 1:
        lines.append("A 1")


lines.append("{}".format(Q))

if method == 'wremove':
    wremove()
elif method == 'noremove':
    noremove()
elif method == 'addremove':
    add_then_remove_all()

sys.stdout.write('\n'.join(lines))
sys.stdout.write('\n')
