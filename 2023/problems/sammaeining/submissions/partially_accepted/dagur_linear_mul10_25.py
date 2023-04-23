#!/usr/bin/env python3
from copy import deepcopy

m = 10**9 + 7
size = 10

def expo(base, expo, m):
	res = 1
	for x in range(expo):
		res *= base
		res %= m
	return res
	
n = int(input())

if n <= 3:
	print(0)
	exit()
elif n == 4:
	print(2)
	exit()

nFloor = int(n // 10)

delta = (expo(4, int(nFloor), m) * 500000004) % m

guess = expo(2, nFloor * 10, m) + 4 * expo(2, nFloor * 2, m)
guess *= 700000005
guess %= m

print((guess - delta) % m)
