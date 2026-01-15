from fractions import Fraction

# Formula
# (2x^2 + 224x + 795)^2 / 100


def get_value(x):
    return Fraction((2 * (x**2) + 224 * x + 795) ** 2) / Fraction(100)


n = Fraction(int(input()))

l = 0
r = 10**64

ans = 10**64
while l <= r:
    m = (l + r) // 2

    if n <= get_value(m):
        ans = m
        r = m - 1
    else:
        l = m + 1

print(ans)
