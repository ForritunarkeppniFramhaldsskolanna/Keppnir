#!/usr/bin/env python2

import re
import sys

n = int(sys.stdin.readline().strip())
assert n % 2 != 0
assert n > 5
assert sys.stdin.read() == ''
sys.exit(42)
