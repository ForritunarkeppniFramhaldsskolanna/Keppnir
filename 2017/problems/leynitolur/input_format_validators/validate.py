import sys
import re

for L in range(100):
    line = sys.stdin.readline()
    assert re.match('^[0-9]+\n$', line)
    n = int(line.strip())

    assert 0 <= n < 2**64

    a = 230309227
    b = 68431307
    c = 2**64

    inv = 881051043651

    x = (n - b) * inv % c
    assert 0 <= x <= 10**18
    assert (x*a + b) % c == n

assert sys.stdin.read() == ''
sys.exit(42)

