#!/usr/bin/env python3
from copy import deepcopy

m = 10**9 + 7
size = 10

n = int(input())

if n <= 3:
	print(0)
	exit()
elif n == 4:
	print(2)
	exit()

nFloor = int(n // 10)

delta = (pow(4, int(nFloor), m) * pow(2, m - 2, m)) % m

guess = pow(2, nFloor * 10, m) + 4 * pow(2, nFloor * 2, m)
guess *= pow(size, m - 2, m)
guess %= m

print((guess - delta) % m)
