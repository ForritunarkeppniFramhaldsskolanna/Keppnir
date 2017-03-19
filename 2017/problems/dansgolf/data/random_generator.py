#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

n = eval(sys.argv[1])
m = eval(sys.argv[2])
K = eval(sys.argv[3])
random.seed(int(sys.argv[4]))

while True:
    k = random.randint(1,min(K,n+m-2))

    diag = set()
    while len(diag) < k:
        diag.add(random.randint(-(m-1),n-1))
    diag = list(diag)

    fail = 0
    used = set()
    for it in range(k):
        while fail < 100:
            d = random.choice(diag)
            # 1 <= x <= n
            # 1+d <= x <= m+d
            # x-d = y
            lo = max(1,1+d)
            hi = min(n,m+d)
            x = random.randint(lo,hi)
            y = x-d
            assert x-y == d
            assert 1 <= x <= n
            assert 1 <= y <= m
            if (x,y) in used:
                fail += 1
                continue
            fail = 0
            used.add((x,y))
            break
        if fail == 100:
            break
    if fail == 100:
        continue

    print('%d %d %d' % (n,m,k))
    used = list(used)
    for (x,y) in used:
        print('%d %d' % (x,y))
    break

