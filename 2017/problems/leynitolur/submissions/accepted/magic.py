import sys

for line in sys.stdin.read().strip().split():
    n = int(line)
    a = 230309227
    b = 68431307
    c = 2**64

    inv = 881051043651

    x = (n - b) * inv % c
    assert 0 <= x <= 10**18
    assert (x*a + b) % c == n

    print(x)

