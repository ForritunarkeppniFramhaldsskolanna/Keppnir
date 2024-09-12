#!/usr/bin/python3
import sys
import string
from random import seed, randint, choice
from functools import reduce

seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
repeat = eval(sys.argv[2])

case = sys.argv[1]

n = choice([max_n, randint(max_n // 2, max_n)])
chars = list(string.ascii_lowercase) + [' ']

outp = []
while len(outp) < n - 1:
    nxt = choice(chars)
    if len(outp) == 0 and nxt == ' ':
        continue
    if len(outp) == n - 1 and nxt == ' ':
        continue
    if len(outp) > 0 and nxt == ' ' and outp[-1] == ' ':
        continue
    if len(outp) != 0 and len(outp) != n - 1 and outp[-1] != ' ':
        if randint(1, 4) != 1:
            nxt = outp[-1]
    if len(outp) > 1 and (not repeat) and nxt == outp[-1] and outp[-2] == outp[-1]:
        continue
    outp.append(nxt)

print("".join(outp))
