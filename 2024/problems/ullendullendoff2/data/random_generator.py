#!/usr/bin/python3
import random
import string
import sys

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])

n = random.randint(min_n, max_n)

names = set()
while len(names) < n:
    name = ''.join(random.choices(string.ascii_lowercase, k=random.randint(1, 10)))
    names.add(name)

names = list(names)
random.shuffle(names)

print(n)
for name in names:
    print(name)
