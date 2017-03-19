#!/usr/bin/env python2

from __future__ import print_function
from __future__ import division
import string
import subprocess
import random
import math
import sys
import string

ends_with_a = eval(sys.argv[1])
method = sys.argv[2]
if method == 'exactly':
    ex = sys.argv[3]
    random.seed(int(sys.argv[4]))
else:
    random.seed(int(sys.argv[3]))

def gen_exactly(s):
    return s

def gen_random():
    chars = string.ascii_lowercase
    size = random.randint(4, 1000)
    return "".join(random.choice(chars) for i in range(size))

def gen_almost_correct():
    vowels = ['a']
    size = random.randint(4, 1000)
    arrs = random.randint(1, size)
    vowelssize = random.randint(2, size-arrs)
    return "b" + "".join(random.choice(['r']) for i in range(arrs)) + "".join(random.choice(vowels) for i in range(vowelssize))

def gen_correct():
    size = random.randint(4, 1000)
    arrs = random.randint(1, size)
    vowels = random.randint(1, size-arrs)
    return "b" + "".join(random.choice(['r']) for i in range(arrs)) + 'a'

def gen_correct_mult_vowels():
    vowels = ['a', 'e', 'i', 'o', 'u', 'y']
    chars = string.ascii_lowercase
    size = random.randint(4, 1000)
    arrs = random.randint(1, size)
    vowelssize = random.randint(1, size-arrs)
    return "b" + "".join(random.choice(['r']) for i in range(arrs)) + "".join(random.choice(vowels))

while True:
    if method == "exactly":
        ans = gen_exactly(ex)
    elif method == "illegal":
        ans = gen_random()
    elif method == "almost_correct":
        ans = gen_almost_correct()
    elif method == "correct":
        ans = gen_correct()
    elif method == "correct_mult_vowels":
        ans = gen_correct_mult_vowels()
    if ends_with_a:
        if ans[-1] != 'a':
            continue
    break

print(ans)
