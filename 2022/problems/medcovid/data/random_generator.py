#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

# minimum size of string
min_n = int(sys.argv[1])
max_n = int(sys.argv[2])

# should include COV
incl = int(sys.argv[3])

# placement
# 2, do nothing, 1 front, 0 in the back
place = int(sys.argv[4])


n = random.randint(min_n, max_n)
# Alphabet includes ACGTOV
alp = "ACGTOV"

out = []
for x in range(n):
    position = random.randint(0, len(alp) - 1)
    out.append(alp[position])

if incl:
    pos = random.randint(0, len(out) - 3)
    if place == 0:
        pos = 0
    elif place == 1:
        place = len(out) - 3
    out[pos] = 'C'
    out[pos + 1] = 'O'
    out[pos + 2] = 'V'
else:
    # make sure that it is not included
    for x in range(len(out)-2):
        if out[x] == 'C' and out[x+1] == 'O' and out[x+2] == 'V':
            out[x] = 'A'

sys.stdout.write("{}\n".format("".join(out)))

