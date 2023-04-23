#!/usr/bin/python3
import sys
import random
import math

random.seed(int(sys.argv[-1]))

tp = sys.argv[1]
max_a = eval(sys.argv[2].lstrip('0'))
max_b = eval(sys.argv[3])
config = sys.argv[4]

a = random.randint(1, max_a)
b = random.randint(1, max_b)

if tp == "A":
    a = 100
    b = 50
    Klim = 1000
elif tp == "B":
    Klim = 500 * min((a,b))
else:
    Klim = 10**5 * min((a, b))

K = 0
if config == "K-Zero":
    K = 0
elif config == "Random":
    K = random.randint(1, Klim)
elif config == "egcd":
    K = max_a if tp == "A" else Klim + 1
    while K > Klim:
        x = random.randint(1, K // a)
        y = random.randint(1, K // b)
        K = (a*x) + (b*y)

print(K)
print(a)
print(b)
