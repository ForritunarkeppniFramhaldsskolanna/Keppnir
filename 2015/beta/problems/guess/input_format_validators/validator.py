import sys
import re

k = sys.stdin.readline()
assert re.match('^[0-9]+\n$', k)
k = int(k.strip())
assert 1 <= k <= 100


mn = -100000
mx = 2**60

for l in range(k):
    line = sys.stdin.readline()
    assert re.match('^x .+? [0-9]+\n$', line)
    x, op, n = line.strip().split()
    n = int(n)
    assert 0 <= n <= 2**30

    if op == '<': mx = min(mx, n - 1)
    elif op == '<=': mx = min(mx, n)
    elif op == '>': mn = max(mn, n + 1)
    elif op == '>=': mn = max(mn, n)
    else: assert False

assert mn <= mx
assert mn >= 0
assert mx <= 2**30
assert mx - mn + 1 <= 1000

assert sys.stdin.read() == ''
sys.exit(42)
