#!/usr/bin/python3
import random

n = int(input())
to_check = list(range(n))
random.shuffle(to_check)

for i in to_check:
    print("?", *[1 if i == j else 0 for j in range(n)])
    s = int(input())
    if s == n + 1:
        print("!", i + 1)
        exit(0)
