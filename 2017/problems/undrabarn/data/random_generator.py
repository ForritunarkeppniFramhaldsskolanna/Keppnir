#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

method = sys.argv[1]

if method == 'small':
    a = random.randint(1, 10**4)
if method == 'large':
    a = random.randint(1, 10**12)
print(a)
