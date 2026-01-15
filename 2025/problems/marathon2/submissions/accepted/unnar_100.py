from collections import defaultdict
from fractions import Fraction
from math import floor
from bisect import bisect_left

n, x, y = map(int, input().split())
h, s = map(int, input().split())

L = set(int(input()) for i in range(n))

# Marathon is 42195 meters
FINISH = 42195

L.add(0)
L.add(FINISH)
L = sorted(list(L))
n = len(L)

# Find the last water station we can get to from the
# i-th station before we run out of water
nxt = [n for i in range(n)]
for i in range(n):
    nxt[i] = bisect_left(L, L[i] + x) - 1


def calc(start, end, water):
    if end - start > water:
        return Fraction(water, h) + Fraction(end - start - water, s)
    return Fraction(end - start, h)


mem = defaultdict(Fraction)

dp = [Fraction(0, 1) for i in range(n)]

for i in range(n - 2, -1, -1):
    ans = Fraction(10**18, 1)
    # Check that there is a station that we can refill at before water runs out
    if nxt[i] > i and nxt[i] < n:
        ans = y + calc(L[i], L[nxt[i]], x) + dp[nxt[i]]
    # Fill at the next station after we run out of water
    if nxt[i] + 1 < n:
        ans = min(ans, y + calc(L[i], L[nxt[i] + 1], x) + dp[nxt[i] + 1])
    # Jog to the finish
    dp[i] = min(ans, calc(L[i], FINISH, x))

total = dp[0]

hours = floor(total / Fraction(3600, 1))
minutes = floor(total / Fraction(60, 1)) % 60
seconds = floor(total) % 60

print(f"{hours:02d}:{minutes:02d}:{seconds:02d}")
