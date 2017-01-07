import sys
import re

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
n = int(n)
assert 1 <= n <= 35

for i in range(n):
    x = sys.stdin.readline()
    assert re.match('^[0-9]\\.[0-9]{10}\n$', x)

assert sys.stdin.read() == ''
sys.exit(42)
