import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*\n$', line)
L, R, k = map(int, line.split())

assert 1 <= L <= R <= 10**14
assert 1 <= k <= 20

line = sys.stdin.readline()
assert re.match('^(0|[1-9][0-9]*)( (0|[1-9][0-9]*))*\n$', line)

a = list(map(int, line.split()))
assert len(a) == k

def is_prime(n):
    i = 1
    while i*i <= n:
        if n%i == 0:
            return True
        i += 1
    return False

for x in a:
    assert 0 <= x <= 8000
    assert is_prime(x)

assert not sys.stdin.read()
sys.exit(42)
