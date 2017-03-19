#!/usr/bin/env python2
import sys

a = 230309227
b = 68431307
c = 2**64
n = int(sys.argv[1])
print((a * n + b) % c)

