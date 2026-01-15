from fractions import Fraction
from math import floor


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


mask = 0

ans = 10**9

if h == s:
    ans = Fraction(FINISH, h)
elif n <= 18:
    for mask in range(1 << n):
        water = x
        sm = 0
        sm += calc(0, L[0], water)
        water = max(0, water - (L[0]))

        for i in range(n):
            # We stop at station i
            if mask & (1 << i):
                water = x
                sm += y
            sm += calc(L[i], L[i + 1], water)
            water = max(0, water - (L[i + 1] - L[i]))
        ans = min(ans, sm)

hours = floor(ans / Fraction(3600, 1))
minutes = floor(ans / Fraction(60, 1)) % 60
seconds = floor(ans) % 60

print(f"{hours:02d}:{minutes:02d}:{seconds:02d}")
