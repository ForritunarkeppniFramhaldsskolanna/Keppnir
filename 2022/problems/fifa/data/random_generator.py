#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

max_n = eval(sys.argv[1])
max_k = eval(sys.argv[2])
s = sys.argv[3]

k = random.randint(1, max_k)
n = random.randint(0, max_n)

if s == "edge":
	n = random.randint(max_n-100, max_n)


n -= n % k

if s == "same":
	print(k)
	print(k)
else:
	print(n)
	print(k)
