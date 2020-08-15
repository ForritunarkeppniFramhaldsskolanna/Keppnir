import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n', line)
n,k = [int(x) for x in line.split()]
assert 1 <= n <= 1000
assert 1 <= k <= n

for i in range(n):
    line = sys.stdin.readline()
    assert line[-1] == '\n'
    line = line[:-1]
    assert len(line) == n
    assert set(line) <= set('#.123456789')

assert not sys.stdin.read()
sys.exit(42)
