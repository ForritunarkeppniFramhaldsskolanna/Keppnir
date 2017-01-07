import sys
import re

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
n = int(n.strip())
assert 1 <= n <= 5

for i in range(n):
    s = sys.stdin.readline()
    assert re.match('^[a-z]+\n$', s)
    s = s.strip()
    assert 1 <= len(s) <= 15

assert sys.stdin.read() == ''
sys.exit(42)
