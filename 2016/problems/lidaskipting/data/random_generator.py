#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

method = sys.argv[1]
if method == 'fixed':
    print(sys.argv[2])
elif method == 'random':
    m = int(sys.argv[2])
    n = int(sys.argv[3])
    random.seed(int(sys.argv[4]))

    print(random.randint(1, (n-m)//3) * 3 + m)
