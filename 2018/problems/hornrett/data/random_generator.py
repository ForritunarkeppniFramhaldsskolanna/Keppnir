import sys
from math import sqrt
from random import randint
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

lo,hi,tp = map(int, sys.argv[1:4])
if tp == 0:
    while True:
        a,b,c = sorted((randint(lo,hi), randint(lo,hi), randint(lo,hi)))
        if a**2 + b**2 != c**2:
            sys.stdout.write("%d %d %d\n" % (a, b, c))
            break
else:
    while True:
        u = randint(int(sqrt(lo)), 2*int(sqrt(hi)))
        v = randint(int(sqrt(lo)), 2*int(sqrt(hi)))
        if u%2 == v%2 or v <= u or gcd(u, v) != 1:
            continue
        a = v**2-u**2
        b = 2*u*v
        c = v**2+u**2
        k = randint(lo//c, hi//c)
        a *= k
        b *= k
        c *= k
        if a > b:
            a,b = b,a
        if lo <= a <= hi and lo <= b <= hi and lo <= c <= hi and a**2 +b**2 == c**2:
            sys.stdout.write("%d %d %d\n" % (a, b, c))
            break
