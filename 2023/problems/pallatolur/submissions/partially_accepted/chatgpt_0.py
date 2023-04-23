#!/usr/bin/python3
a, b = map(int, input().split())

def print_primes(a, b):
    primes = [True] * (b - a + 1)
    if a == 1:
        primes[0] = False
    for i in range(2, int(b ** 0.5) + 1):
        for j in range(max(i * i, (a + i - 1) // i * i), b + 1, i):
            primes[j - a] = False
    count = 0
    for i in range(a, b + 1):
        if primes[i - a]:
            count += 1
    if count == 0:
        print(':(')
    else:
        print(count)
        for i in range(a, b + 1):
            if primes[i - a]:
                print(i, end=' ')

print_primes(a, b)
