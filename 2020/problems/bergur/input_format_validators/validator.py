import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 3*10**5

line = sys.stdin.readline().split()
assert len(line) == n
for x in line:
    assert 1 <= int(x) <= 10**4

assert not sys.stdin.read()
sys.exit(42)
