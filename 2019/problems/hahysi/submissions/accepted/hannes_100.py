#!/usr/bin/env python3
import math

n, m = [int(i) for i in input().split()]

a = (n*(n-1))//2
b = (m*(m-1))//2
mod = (10**9) + 7
res = a * b
print(res % mod)
