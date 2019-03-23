import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 2*10**5

for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
    x, c = map(int, line.split())
    assert 1 <= x <= 10**9
    assert 1 <= c <= 10**3

assert not sys.stdin.read()
sys.exit(42)
