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

def powsum(x, a, b, m):
    if a == b:
        return modpow(x, a, m)
    c = a + (b - a) // 2
    v = powsum(x, a, c, m)
    sm = v + v * modpow(x, b - c, m)
    if 2 * c == a + b:
        sm -= modpow(x, c, m)
    return (sm % m + m) % m
        
res = modpow(a, n, m) * x0 + powsum(a, 0, n - 1, m) * b
print((res % m + m) % m)
