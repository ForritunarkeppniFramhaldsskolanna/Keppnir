import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n,x = map(int, line.split())

assert 1 <= n <= 1000
assert 1 <= x <= 5000

for x in range(n):
    line = sys.stdin.readline()
    l,r,a = map(int,line.split())
    assert 1 <= l <= 5000
    assert 1 <= r <= 5000
    assert 1 <= a <= 500
    assert l <= r

assert not sys.stdin.read()
sys.exit(42)
