from collections import defaultdict
from fractions import Fraction
from math import floor
import sys

sys.setrecursionlimit(10**5)

n, x, y = map(int, input().split())
h, s = map(int, input().split())

L = sorted(list(int(input()) for i in range(n)))

# Marathon is 42195 meters
FINISH = 42195

L.append(FINISH)


def calc(start, end, water):
    if end - start > water:
        return Fraction(water, h) + Fraction(end - start - water, s)
    return Fraction(end - start, h)


mem = defaultdict(Fraction)


def dp(at, water):
    # Last drink station
    if at == n:
        return 0

    if (at, water) in mem:
        return mem[(at, water)]

    # Refill here
    ans = y + calc(L[at], L[at + 1], x) + dp(at + 1, max(0, x - (L[at + 1] - L[at])))
    # Don't refill
    ans = min(ans, calc(L[at], L[at + 1], water) + dp(at + 1, max(0, water - (L[at + 1] - L[at]))))

    mem[(at, water)] = ans
    return ans


total = 0

if h == s:
    total = Fraction(FINISH, h)
else:
    total = calc(0, L[0], x) + dp(0, max(0, x - L[0]))

hours = floor(total / Fraction(3600, 1))
minutes = floor(total / Fraction(60, 1)) % 60
seconds = floor(total) % 60

print(f"{hours:02d}:{minutes:02d}:{seconds:02d}")
