import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*\\n$', line)
n,m,k = map(int, line.split())

assert 1 <= n <= 10**5
assert 1 <= m <= n
assert 1 <= k <= 10**7

line = sys.stdin.readline()
A = [int(x) for x in line.split()]
for x in A:
    assert 1 <= x <= 10**7

line = sys.stdin.readline()
B = [int(x) for x in line.split()]
for x in B:
    assert 1 <= x <= 10**7
assert not sys.stdin.read()
sys.exit(42)
