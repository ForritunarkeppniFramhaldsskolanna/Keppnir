#!/bin/usr/python3
from math import sqrt

def batman(a, b, c):
    d = b*b - 4*a*c
    if d < 0: return -1
    sqrtd = int(sqrt(d))
    if sqrtd*sqrtd == d:
        n1, n2 = -b + sqrtd, -b - sqrtd
        den = 2*a
        if n1 % den == 0 and n1 > den:
            return n1//den
        if n2 % den == 0 and n2 > den:
            return n2//den
    return -1

n, d = map(int, input().split())

ans = 0
b = 2
while (b-3)*(b-3)*(b-3) <= n+1:
    cnt = 0
    m = n
    while m > 0:
        if m%b == d:
            cnt += 1
        m //= b
    ans = max(ans, cnt)
    b += 1

if n > 2*d and ans == 0:
    ans = 1

if n%d == 0 and n//d-1 > d and ans < 2:
    ans = 2

i = 0
while (i-3)*(i-3)*(i-3) <= n:
    if i > 0:
        b = batman(i, d, d-n)
        if b > 0 and i*b*b + d*b + d == n:
            ans = max(ans, 2)
    b = batman(d, i, d-n)
    if b > 0 and d*b*b + i*b + d == n:
        ans = max(ans, 2)
    b = batman(d, d, i-n)
    if b > 0 and d*b*b + d*b + i == n:
        ans = max(ans, 2)
    i += 1

if n == d:
    ans = 1
if d > n:
    ans = 0

print(ans)
