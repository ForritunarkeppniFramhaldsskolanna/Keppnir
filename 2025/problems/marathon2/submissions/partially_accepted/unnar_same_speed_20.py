from fractions import Fraction
from math import floor

n, x, y = map(int, input().split())
h, s = map(int, input().split())

L = sorted(list(int(input()) for i in range(n)))

# Marathon is 42195 meters
FINISH = 42195

total = Fraction(FINISH, h)

hours = floor(total / Fraction(3600, 1))
minutes = floor(total / Fraction(60, 1)) % 60
seconds = floor(total) % 60

print(f"{hours:02d}:{minutes:02d}:{seconds:02d}")
