#!/usr/bin/env python

from __future__ import print_function
from __future__ import division
import random
import sys

method = sys.argv[1]

if method == 'fixed':
    print('%s %s' % tuple(sys.argv[2:4]))
    exit(0)

maxsize = int(sys.argv[2])
random.seed(int(sys.argv[3]))


def randodd(maxsize):
    return 2 * random.randint(0, (maxsize - 1) // 2) + 1

def randeven(maxsize):
    return 2 * random.randint(1, maxsize // 2)

def oddodd(maxsize):
    return '%s %s' % (randodd(maxsize), randodd(maxsize))

def evenodd(maxsize):
    return '%s %s' % (randeven(maxsize), randodd(maxsize))

def oddeven(maxsize):
    return '%s %s' % (randodd(maxsize), randeven(maxsize))

def eveneven(maxsize):
    return '%s %s' % (randeven(maxsize), randeven(maxsize))


print(locals()[method](maxsize))
