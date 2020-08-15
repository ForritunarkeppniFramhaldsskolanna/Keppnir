#!/usr/env/bin python3
a, b, x0, n, m = [int(x) for x in input().strip().split()]

def f(x):
    return ((a * x + b) % m + m) % m

def modpow(b, e, m):
    res = 1
    while e > 0:
        if e % 2 != 0:
            res = ((res * b % m) + m) % m
        b = ((b * b % m) + m) % m
        e //= 2
    return res

def modinv(x, p):
    return modpow(x, p - 2, p)

res = modpow(a, n, m) * x0 + (modpow(a, n, m) - 1) * (modinv(a - 1, m)) * b
print((res % m + m) % m)
