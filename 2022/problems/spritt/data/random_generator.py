#!/usr/bin/python3
import sys
import random

def get_valid_solution(n, x):
	arr = []
	for i in range(n):
		arr.append(random.randint(1, x//n))
	return arr

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
max_x = eval(sys.argv[2])
s = sys.argv[3]


if s == "exact":
	arr = get_valid_solution(max_n, max_x)
	print(max_n, sum(arr))
	for i in range(max_n):
		print(arr[i])

elif s == "edge":
	arr = get_valid_solution(max_n, max_x)
	print(max_n, sum(arr) - 1)
	for i in range(max_n):
		print(arr[i])

else:
	n = random.randint(1, max_n)
	print(n, random.randint(1, max_x))

	for i in range(n):
		print(random.randint(1, max_x//n))



