#!/usr/bin/env python3
from itertools import combinations

m = 10**9 + 7
n = int(input())
S = list(range(1, n + 1))
soln = 0

for x in range(n + 1):
	for comb in combinations(S, x):
		if sum(comb) % 10 == 7:
			soln += 1
print(soln % m)
