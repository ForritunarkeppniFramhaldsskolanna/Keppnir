#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

randmin = int(sys.argv[1])
randmax = int(sys.argv[2])
random.seed(int(sys.argv[3]))

n = random.randint(randmin, randmax)

print('%d' % n)

