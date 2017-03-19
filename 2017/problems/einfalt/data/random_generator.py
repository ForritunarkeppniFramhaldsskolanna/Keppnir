#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

lo = int(sys.argv[1])
hi = int(sys.argv[2])
random.seed(int(sys.argv[3]))

print(random.randint(lo,hi))

