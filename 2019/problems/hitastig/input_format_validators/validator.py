import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)

assert 1 <= n <= 1000

line = sys.stdin.readline()
arr = [int(x) for x in line.split()]
assert len(arr) == n
arr = sorted(arr)
for x in range(n):
    assert -10**18 <= x <= 10**18

assert not sys.stdin.read()
sys.exit(42)
