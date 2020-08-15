#!/usr/env/bin python3
a, b, x0, n, m = [int(x) for x in input().strip().split()]

def f(x):
    return ((a * x + b) % m + m) % m

for i in range(n):
    x0 = f(x0)

print(x0)
