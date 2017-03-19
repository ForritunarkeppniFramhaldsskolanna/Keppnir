#!/usr/bin/env python3
primes = [2, 3, 61]
mod = 0

def pow(x, p):
    if p == 0:
        return 1;
    return pow(x * x % mod, p // 2) * (1, x)[p % 2] % mod;

def check(x):
    global mod
    mod = x
    for p in primes:
        if p != x and pow(p, x - 1) != 1:
            return 0
    return 1

n = int(input())
for i in range(4, n, 2):
    if check(n - i):
        for j in range(2, i):
            if check(j) and check(i - j):
                print(j, i - j, n - i)
                exit()
