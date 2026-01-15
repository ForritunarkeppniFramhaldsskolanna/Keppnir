#!/usr/bin/env python3
import sys
import random

from string import ascii_letters

random.seed(int(sys.argv[-1]))

min_n = int(sys.argv[1])
max_n = int(sys.argv[2])

min_l = int(sys.argv[3])
max_l = int(sys.argv[4])

min_t = int(sys.argv[5])
max_t = int(sys.argv[6])

min_w = int(sys.argv[7])
max_w = int(sys.argv[8])


n = random.randint(min_n, max_n)
l = random.randint(min_l, max_l)
t = random.randint(min_t, max_t)

words = ["".join(random.choice(ascii_letters) for _ in range(random.randint(min_w, max_w))) for _ in range(n)]

sys.stdout.write(f"{n} {l} {t}\n")
sys.stdout.write(f"{' '.join(words)}\n")
