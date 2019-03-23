import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n,q = map(int, line.split())

assert 1 <= n <= 10**5
assert 1 <= q <= 10**5
for x in range(q):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
    a,b = map(int, line.split())
    assert 1 <= a <= 10**5
    assert 1 <= b <= n




assert not sys.stdin.read()
sys.exit(42)
