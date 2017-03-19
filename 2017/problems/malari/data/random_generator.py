#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

# Usage: random_generator N M s
# N size of wall
# M number of intervals
# s random number genertor seed

method = sys.argv[1]
n_lim = int(sys.argv[2])
m_lim = int(sys.argv[3])
random.seed(int(sys.argv[4]))

def gen_random_interval(N):
    i = random.randint(1,N)
    j = random.randint(1,N)
    if i > j:
        i,j = j,i
    return str(i) + ' ' + str(j)

def gen_random_big_interval(N):
    L = random.randint(N//2,N)
    i = random.randint(1,N-L+1)
    j = i+L-1
    if i > j:
        i,j = j,i
    return str(i) + ' ' + str(j)


print('%d %d' % (n_lim,m_lim))
for i in range(m_lim):
    if method == 'random':
        print(gen_random_interval(n_lim))
    else:
        print(gen_random_big_interval(n_lim))


