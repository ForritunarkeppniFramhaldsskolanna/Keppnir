#!/usr/bin/python3
import sys
import random
import string

random.seed(int(sys.argv[-1]))


def rand_str(l):
    res = [random.choice(string.digits + string.ascii_letters) for _ in range(l)]
    return "".join(res)


ending_len = int(sys.argv[1])
many_dots = eval(sys.argv[2])

extra_len = random.randint(0, 32 - ending_len - 1)
name = rand_str(extra_len)
if many_dots and extra_len > 0:
    name = list(name)
    ch = random.randint(1, min(5, len(name)))
    for i in random.sample(range(len(name)), ch):
        name[i] = "."
    name = "".join(name)

ending = rand_str(ending_len)
print(name + "." + ending)
