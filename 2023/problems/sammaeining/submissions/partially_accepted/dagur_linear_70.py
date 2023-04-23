#!/usr/bin/env python3
from copy import deepcopy

m = 10**9 + 7
size = 10
arr = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0]
arr2 = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0]

n = int(input())
for x in range(1, n + 1):
	for idx in range(10):
		arr[(idx + x) % size] += arr2[idx]
		arr[(idx + x) % size] %= m
	for idx in range(10):
		arr2[idx] = arr[idx]

# print(arr)
print(arr[7] % m)
