#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

COORD_BOUND = 10**4

n = int(sys.argv[1])
x0 = sys.argv[2] == 'True'
ypos = sys.argv[3] == 'True'
method = sys.argv[4]
random.seed(int(sys.argv[5]))

def gen_random(n,x0,ypos):
    return [ (0 if x0 else random.randint(-COORD_BOUND, COORD_BOUND), random.randint(0 if ypos else -COORD_BOUND, COORD_BOUND)) for _ in range(n) ]

def gen_jumps(n):
    assert x0 and not ypos
    pts = []
    l = -2
    r = 1
    pts.append(r)
    pts.append(l)
    sign = 1
    while len(pts) < n and abs(pts[-1]) < COORD_BOUND/8:
        lastd = abs(pts[-1] - pts[-2])
        pts.append(pts[-2] + sign * lastd + sign)
        sign = -sign

    mn = min(pts)
    mx = max(pts)
    while len(pts) < n:
        if random.randint(0,1) == 0:
            pts.append(random.randint(-COORD_BOUND, mn))
        else:
            pts.append(random.randint(mx, COORD_BOUND))

    return [ (0,pts[i]) for i in range(n) ]

if method == 'random':
    pts = gen_random(n, x0, ypos)
elif method == 'jumps':
    pts = gen_jumps(n)
else:
    assert False

print(n)
random.shuffle(pts)
for (x,y) in pts:
    print('%d %d' % (x,y))

