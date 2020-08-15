#!/usr/env/bin python3
a, b, x0, n, m = [int(x) for x in input().strip().split()]

def f(x):
    return ((a * x + b) % m + m) % m

def floyd(x0, f):
    t, h, mu, lam = f(x0), f(f(x0)), 0, 1
    while t != h:
        t, h = f(t), f(f(h))
    h = x0
    while t != h:
        t, h, mu = f(t), f(h), mu + 1
    h = f(t)
    while t != h:
        h, lam = f(h), lam + 1
    return mu, lam

mu, lam = floyd(x0, f)

def g(x, n):
    for i in range(n):
        x = f(x)
    return x

if mu >= n:
    print(g(x0, n))
else:
    x0 = g(x0, mu)
    n -= mu
    n %= lam
    print(g(x0, n))
