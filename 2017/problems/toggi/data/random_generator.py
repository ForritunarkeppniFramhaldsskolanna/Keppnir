#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

method = sys.argv[1]
n = int(sys.argv[2])
random.seed(int(sys.argv[3]))

if method == 'random':
    a = random.randint(1, n)
else:
    a = n
line = str(a)
print('%s' % line)
sys.stderr.write("wrote N={}\n".format(len(line)))

