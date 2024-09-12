#!/usr/bin/python3
import sys
import random
import itertools

random.seed(int(sys.argv[-1]))

max_n = int(sys.argv[1])

n = random.choice([random.randint(max_n // 2, max_n), max_n])
c = random.randint(0, 10 ** 3)
print(n, c)

chars = []
for i in range(ord('a'), ord('z') + 1):
    chars.append(chr(i))
for i in range(ord('A'), ord('Z') + 1):
    chars.append(chr(i))

l, tot = 1, 52
while tot < n:
    l += 1
    tot *= 52

names = ["".join(poss) for poss in itertools.product(chars, repeat=l)]
random.shuffle(names)

for i in range(n):
    a = random.randint(0, 10 ** 3)
    b = random.randint(0, 10 ** 3)
    print(names[i], a, b)

