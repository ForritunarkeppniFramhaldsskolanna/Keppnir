#!/usr/bin/python3
import random
import string
import sys

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])
prefix = sys.argv[3]

assert min_n >= len(prefix), "Prefix is longer than minimum length"

n = random.randint(min_n, max_n)
m = n - len(prefix)

word = prefix + ''.join(random.choices(string.ascii_lowercase, k=m))
print(word)
