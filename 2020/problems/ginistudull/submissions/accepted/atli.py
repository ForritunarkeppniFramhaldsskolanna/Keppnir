#!/usr/env/bin python3
n = int(input())
y = sorted([int(input()) for i in range(n)])

S, T = 0, 0

for i in range(n):
    S += y[i]
    T += (2 * i - n + 1) * y[i]

print("{:.9f}".format(float(T) / S / n))
