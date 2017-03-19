import sys

def xgcd(b, n):
    x0, x1, y0, y1 = 1, 0, 0, 1
    while n != 0:
        q, b, n = b // n, n, b % n
        x0, x1 = x1, x0 - q * x1
        y0, y1 = y1, y0 - q * y1
    return b, x0, y0

for line in sys.stdin.read().strip().split():
    n = int(line)
    a = 230309227
    b = 68431307
    c = 2**64

    g, x, y = xgcd(a, c)
    assert g == 1
    assert (x * a) % c == 1

    ans = (n - b) * x % c
    assert 0 <= ans <= 10**18
    assert (ans*a + b) % c == n

    print(ans)

