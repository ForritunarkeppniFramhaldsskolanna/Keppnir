#!/usr/bin/python3

import random
import math
import itertools


def rho(n):
    for s in [2, 3, 5, 7, 11, 13, 1031]:
        x, y, d = s, s, 1
        while d == 1:
            x = (x * x + 1) % n
            y = (y * y + 1) % n
            y = (y * y + 1) % n
            d = math.gcd(abs(x - y), n)
        if d == n:
            continue
        return d
    return -1


def is_probable_prime(n, k):
    if n % 2 == 0:
        return n == 2
    if n <= 3:
        return n == 3
    s, d = 0, n - 1
    while d % 2 == 0:
        d //= 2
        s += 1
    for _ in range(k):
        a = random.randint(2, n - 1)
        x = pow(a % n, d, n)
        if x == 1 or x == n - 1:
            continue
        ok = False
        for i in range(s - 1):
            x = (x * x) % n
            if x == 1:
                return False
            if x == n - 1:
                ok = True
                break
        if not ok:
            return False
    return True


eratos = [i for i in range(100000)]

i = 2
while i * i < 100000:
    if eratos[i] == i:
        for j in range(i * i, 100000, i):
            eratos[j] = i
    i += 1


def factors(x):
    cnt = dict()
    for i in range(2, 100000):
        if eratos[i] != i:
            continue
        while x % i == 0:
            x //= i
            if i not in cnt:
                cnt[i] = 0
            cnt[i] += 1
    st = [x]
    while len(st) > 0:
        y = st[-1]
        st.pop()
        if y == 1:
            continue
        if y in cnt or is_probable_prime(y, 5):
            if y not in cnt:
                cnt[y] = 0
            cnt[y] += 1
        else:
            d = rho(y)
            st.append(d)
            st.append(y // d)
    return cnt


def odd_divisors(x):
    fac = factors(x)
    if 2 in fac:
        del fac[2]
    fac = list(fac.items())
    for e in itertools.product(*[range(ei + 1) for _, ei in fac]):
        ml = 1
        for i in range(len(fac)):
            ml *= fac[i][0] ** e[i]
        yield ml


x = int(input())
for y in odd_divisors(x):
    f = x // y - (y - 1) // 2
    if f < 1:
        y -= -2 * f + 1
        f = -f + 1
    print(f, y)
