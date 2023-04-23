#!/usr/bin/python3
def tax(n):
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False
    primes = []
    for i in range(2, n + 1):
        if sieve[i]:
            primes.append(i)
            for j in range(2 * i, n + 1, i):
                sieve[j] = False
    taken = []
    for p in primes[::-1]:
        for i in range(p, n + 1, p):
            if sieve[i]:
                taken.append(i)
                for j in range(2 * i, n + 1, i):
                    sieve[j] = False
    return taken

n = int(input().strip())
taken = tax(n)
print(len(taken))
print(*taken)
