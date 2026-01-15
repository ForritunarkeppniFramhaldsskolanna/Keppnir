#!/usr/bin/python3
import random

random.seed(1337)
n = int(input())
while True:
    i = random.randint(1, n)
    j = random.randint(1, n)
    if i == j:
        continue
    print(i, j, flush=True)
    if input().strip() == "Ljos!":
        exit(0)
