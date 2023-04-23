#!/usr/bin/env python3

"""
Answer is given as coefficient of x^7 in (1+x)(1+x^2)...(1+x^n)
in the ring Z_mod[X] / (x^10 - 1)

Not too hard to get that for large enough n (> 5) we get
that the answer is half of the answer in the ring
Z_mod[X] / (x^5 - 1)

Since x^5 = 1 in the ring we get (1+1)^r0(1+x)^r1...(1+x^4)^r4
Simplest case is when 1+x^n = 1+x^0 in the ring, then the ri are
all equal, so get a simpler binomial sum to work with

In this particular case we get (32^(n/5) - 2^(n/5))/5 by linear
recurrence relations

To get 1 mod 5 we double the previous answer
To get 2 mod 5 we double the previous answer and add 2^(n/5)
To get 3 mod 5 we double the previous answer and subtract 2^(n/5)
To get 4 mod 5 we double the previous answer and add 2^(n/5)

Had the modulo m been fixed and small, like I initially interpreted
the problem we could have calculated (1+x)...(1+x^n) coefficients
directly by collecting like above then reduce the ri with respect
to the modulo, making them of bounded size. Then we would only
have needed to reduce n w.r.t. the modulo, which is technically
still log(n) I suppose. My bad.
"""

mod = 10 ** 9 + 7
n = int(input())

if n < 10:
    print([0, 0, 0, 0, 2, 3, 6, 13, 25, 51][n])
    exit()

k, r = divmod(n, 5)
ans = ((pow(32, k, mod) - pow(2, k, mod) + mod) * pow(5, mod-2, mod)) % mod

if r >= 1:
    ans *= 2
    ans %= mod

if r >= 2:
    ans *= 2
    ans += pow(2, k, mod)
    ans %= mod

if r >= 3:
    ans *= 2
    ans += mod - pow(2, k, mod)
    ans %= mod

if r >= 4:
    ans *= 2
    ans += pow(2, k, mod)
    ans %= mod

ans *= pow(2, mod-2, mod)
ans %= mod

print(ans)
