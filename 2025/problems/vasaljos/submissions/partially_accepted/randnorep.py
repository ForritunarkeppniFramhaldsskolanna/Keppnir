#!/usr/bin/python3
import random

done = set()
random.seed(1337)
n = int(input())
while True:
    i = random.randint(1, n)
    j = random.randint(1, n)
    if i >= j:
        continue
    if (i, j) in done:
        continue
    print(i, j, flush=True)
    done.add((i, j))
    if input().strip() == "Ljos!":
        exit(0)
