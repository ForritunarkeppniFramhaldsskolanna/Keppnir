#!/usr/bin/python3
from functools import reduce
from operator import mul
n = int(input())
print((reduce(mul, range(n, n-20, -1), 1) // 8) % 1000000007)
