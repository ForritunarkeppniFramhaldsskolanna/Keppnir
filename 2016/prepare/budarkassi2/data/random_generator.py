#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

n = int(sys.argv[1])
random.seed(int(sys.argv[2]))

print('%d %d' % (random.randint(1, n),
                 random.randint(1, n)))

