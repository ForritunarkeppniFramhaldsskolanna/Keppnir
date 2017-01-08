#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import random
import sys

group = int(sys.argv[1])
n = int(sys.argv[2])
random.seed(int(sys.argv[3]))

print(open('tests').read().split('\n\n')[group].splitlines()[n])

