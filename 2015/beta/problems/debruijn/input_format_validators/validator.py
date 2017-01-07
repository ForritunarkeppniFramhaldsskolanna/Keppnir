import sys
import re

line = sys.stdin.readline()
assert re.match('^[0-9]+ [0-9]+\n$', line)
k, n = map(int, line.strip().split())
assert 2 <= k <= 26
assert 1 <= n <= 20
assert k**n <= 5 * 10**5

line = sys.stdin.readline()
assert re.match('^[a-z]+\n$', line)

line = line.strip()
assert len(line) == k**n

for c in line:
    assert ord('a') <= ord(c) <= ord('a') + k - 1

assert sys.stdin.read() == ''

sys.exit(42)
