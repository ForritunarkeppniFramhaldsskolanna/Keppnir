#!/usr/bin/env python2

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

n = int(sys.argv[1])
k = int(sys.argv[2])
method = sys.argv[3]
random.seed(int(sys.argv[4]))

def gen_generated():
    nums = []
    for i in range(n):
        nums.append(random.randint(1, k//2))
    s = nums[random.randint(0, n-1)] + nums[random.randint(0, n-1)]
    print("%s %s" % (n,s))
    for i in nums:
        print(i)

def gen_random():
    nums = []
    for i in range(n):
        nums.append(random.randint(1, k//2))
    s = random.randint(1, k)
    print("%s %s" % (n,s))
    for i in nums:
        print(i)

def gen_excluded():
    ans = random.randint(1, k)
    found = set()
    nums = []
    for i in range(n):
        while True:
            x = random.randint(1,k)
            if (ans - x) not in found:
                break
        found.add(x)
        nums.append(x)
    print("%s %s" % (n,ans))
    for i in nums:
        print(i)

if method == "generate":
    gen_generated()
elif method == "random":
    gen_random()
elif method == "excluded":
    gen_excluded()
