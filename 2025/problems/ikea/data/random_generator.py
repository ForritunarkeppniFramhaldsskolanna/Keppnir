#!/usr/bin/python3
import sys
import random
from string import ascii_letters as letters

random.seed(int(sys.argv[-1]))

maxN = int(sys.argv[1]) + 1
kDivN = int(sys.argv[2])
maxGrams = 100000

useGauss = random.randrange(2) == 1


def gauss():
    ret = int(random.gauss(maxGrams / 2, maxGrams / 6))
    ret = min(ret, maxGrams)
    ret = max(ret, 1)
    return ret


seen = set()


def genName():
    while True:
        if maxN < 10:
            name = "".join(random.choices(letters, k=100))
        else:
            name = "".join(random.choices(letters, k=4))
        if name not in seen:
            seen.add(name)
            return name


n = random.randrange(1, maxN)
k = random.randrange(1, maxN)
if kDivN:
    while n % k != 0:
        k = random.randrange(1, maxN)

print(k)
print(n)
for _ in range(n):
    if useGauss:
        print(f"{genName()} {gauss()}")
    else:
        print(f"{genName()} {random.randint(1, maxGrams)}")
