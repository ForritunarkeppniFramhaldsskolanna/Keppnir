#!/usr/bin/env python

import re
import sys

s = sys.stdin.readline()
assert len(s) <= 1000 and re.match("^[a-zA-Z]*\n$", s)
sys.exit(42)
