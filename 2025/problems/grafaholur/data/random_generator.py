#!/usr/bin/python3
import sys
import random


def get_divs(x):
    d = 1
    while d * d <= x:
        if x % d == 0:
            yield d
            if d * d != x:
                yield x // d
        d += 1
    return


random.seed(int(sys.argv[-1]))

force_int = int(sys.argv[1])

if force_int:
    while True:
        x = random.randint(1, 100)
        y = random.randint(1, 100)
        b = random.randint(1, 100)
        val = x * y * b
        az = random.choice(list(get_divs(val)))
        opts = [x for x in get_divs(az) if x <= 100]
        if len(opts) == 0:
            continue
        a = random.choice(opts)
        z = az // a
        if z > 100:
            continue
        print(x)
        print(y)
        print(z)
        print(a)
        print(b)
        break
else:
    for i in range(5):
        print(random.randint(1, 100))
