#!/usr/bin/env python2
# coding: utf-8

from __future__ import print_function
from __future__ import division
import string
import subprocess
import random
import math
import sys
import string

method = sys.argv[1]
random.seed(int(sys.argv[-1]))

def rand(n, l, p):
    ni = n
    s = []
    print(ni)
    for k in range(ni):
        poll = random.uniform(0, 1)
        size = random.randint(1, l)
        if poll <= p or k == 0:
            cur = "".join(random.choice(string.ascii_lowercase) for i in range(size))
        else:
            cur = random.choice(s)
        s.append(cur)
        print(cur)

def atmost(n):
    l = random.randint(1,n)
    cnt = n // l
    print(cnt)
    for _ in range(cnt):
        print("".join(random.choice(string.ascii_lowercase) for i in range(l)))

def srt(n):
    l = int(math.sqrt(n)) + random.randint(-10,10)
    cnt = n // l
    print(cnt)
    for _ in range(cnt):
        print("".join(random.choice(string.ascii_lowercase) for i in range(l)))

if method == "rand":
    rand(int(sys.argv[2]), int(sys.argv[3]), float(sys.argv[4]))
elif method == "atmost":
    atmost(int(sys.argv[2]))
elif method == "sqrt":
    srt(int(sys.argv[2]))
else:
    assert False

