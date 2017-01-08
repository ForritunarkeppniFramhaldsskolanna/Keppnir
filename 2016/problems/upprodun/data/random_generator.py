#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

n = int(sys.argv[1])
mul = sys.argv[2] == 'True'
random.seed(int(sys.argv[3]))

m = random.randint(n, 500)
if mul:
    m = random.randint(1, 500//n)*n

print(n)
print(m)

