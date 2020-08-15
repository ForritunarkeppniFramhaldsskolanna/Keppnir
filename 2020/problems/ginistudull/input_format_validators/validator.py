import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 10**5

for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]*\n$', line)
    y = int(line)
    assert 1 <= y <= 10**5

assert not sys.stdin.read()
sys.exit(42)
