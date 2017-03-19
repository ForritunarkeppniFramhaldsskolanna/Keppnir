#!/usr/bin/env python2

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

upper = int(sys.argv[1])
expr = sys.argv[2]
random.seed(int(sys.argv[-1]))

def is_witness(n, a):
    if a > n-2:
        return False
    d = n-1
    r = 0
    while d % 2 == 0:
        r += 1
        d = d // 2
    x = pow(a, d, n)
    if x == 1 or x == n-1:
        return False
    for i in range(r-1):
        x = x * x % n
        if x == 1:
            return True
        if x == n-1:
            return False
    return True

def is_probable_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    a = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 61, 73, 1662803]
    for x in a:
        if is_witness(n, x):
            return False
    return True

def rp(l,r):
    while True:
        n = random.randint(l,r)
        if is_probable_prime(n):
            return n

gaps = []
with open('gaps.txt', 'r') as f:
    for line in f.read().strip().split('\n'):
        parts = line.split()
        d = int(parts[0].strip('*'))
        n = int(parts[-1])
        gaps.append((n,d))

gaps = sorted(gaps)
def random_gap(l0=None, l1=None, d0=None, d1=None):
    random.shuffle(gaps)
    for (n,d) in gaps:
        if l0 is not None and n < l0:
            continue
        if l1 is not None and n > l1:
            continue
        if d0 is not None and d < d0:
            continue
        if d1 is not None and d > d1:
            continue
        return n+d-2
    assert False

def next_twin_prime(n):
    while not (is_probable_prime(n-2) and is_probable_prime(n)):
        n += 1
    return n

while True:
    num = eval(expr)
    if num % 2 != 0 and 7 <= num <= upper:
        break

print('%d' % num)

