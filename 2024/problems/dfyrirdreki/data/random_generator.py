#!/usr/bin/python3
import sys
import random
from functools import reduce

random.seed(int(sys.argv[-1]))

case = sys.argv[1]

a = random.randint(-100, 100)
if a == 0:
    a += 1
b = random.randint(-100, 100)
c = random.randint(-100, 100)

d = b**2 - 4 * a * c
if case == "2_sol":
    if d == 0:
        c += 1
        d = b**2 - 4 * a * c
    if d < 0:
        a *= -1
elif case == "0_sol":
    if d == 0:
        c += 1
        d = b**2 - 4 * a * c
    if d > 0:
        c *= -1
elif case == "1_sol":
    while True:
        while b**2 % 4 != 0:
            b = random.randint(-100, 100)
        
        r = b**2 // 4
        if r < 0:
            r *= -1
        factors = []
        i = 2
        while r != 1:
            if r % i == 0:
                factors.append(i)
                r //= i
                i -= 1
            i += 1

        random.shuffle(factors)
        a = reduce(lambda x, y: x*y, factors[:len(factors)//2], 1)
        c = reduce(lambda x, y: x*y, factors[len(factors)//2:], 1)

        if a <= 100 and c <= 100:
            break

print(a)
print(b)
print(c)
