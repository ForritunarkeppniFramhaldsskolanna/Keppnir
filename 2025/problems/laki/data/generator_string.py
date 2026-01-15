#!/usr/bin/python3
import sys
import random
import string

random.seed(int(sys.argv[-1]))

l1 = random.randint(0, 50)
l2 = random.randint(0, 50)


def make_str(l):
    avail = string.ascii_letters + "0123456789"
    res = [random.choice(avail) for _ in range(l)]
    return "".join(res)


print('"{}" + "{}"'.format(make_str(l1), make_str(l2)))
