#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

house_order = sys.argv[1]
garage_order = sys.argv[2]
min_n = int(sys.argv[3])
max_n = int(sys.argv[4])

for _ in range(1):
    random.randint(min_n, max_n) # avoid duplicate tests
n = random.randint(min_n, max_n)

houses = [i for i in range(1, n+1)]
garages = [i for i in range(1, n+1)]

def morph(L, order):
    if order == "inc":
        pass
    elif order == "dec":
        L.reverse()
    else:
        random.shuffle(L)

morph(houses, house_order)
morph(garages, garage_order)

print(n)
print(' '.join(str(i) for i in houses))
print(' '.join(str(i) for i in garages))
