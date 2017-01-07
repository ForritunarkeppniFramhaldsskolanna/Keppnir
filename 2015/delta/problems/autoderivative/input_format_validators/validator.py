import sys
import re

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
n = int(n.strip())
assert 1 <= n <= 100
line = sys.stdin.readline().split()
assert len(line) == n + 1
for num in line:
    assert re.match('^([0-9]+)$', num)
assert sys.stdin.read() == ''
sys.exit(42)
