#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

a = int(sys.argv[1])
b = int(sys.argv[2])
random.seed(int(sys.argv[3]))

def gen_random(a,b):
    return random.randint(a,b)

line = str(gen_random(a,b))

print('%s' % line)
sys.stderr.write("wrote N={}\n".format(line))

