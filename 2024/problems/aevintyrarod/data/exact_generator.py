#!/usr/bin/python3
import sys
import random
import itertools
import string

random.seed(int(sys.argv[-1]))

n = int(sys.argv[1])
c = random.randint(0, 10 ** 3)
print(n, c)

chars = list(string.ascii_lowercase) + list(string.ascii_uppercase)

l, tot = 1, 52
while tot < n:
    l += 1
    tot *= 52

names = ["".join(poss) for poss in itertools.product(chars, repeat=l)]
random.shuffle(names)

for i in range(n):
    a = int(sys.argv[2 * i + 2])
    b = int(sys.argv[2 * i + 3])
    print(names[i], a, b)

