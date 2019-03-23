import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)

assert 1 <= n <= 5*10**5

line = sys.stdin.readline()
assert re.match('^([1-9][0-9]*)( ([1-9][0-9]*))*\n$', line)

a = map(int, line.split())
assert len(a) == n

for x in a:
    assert 1 <= x <= 1000000

assert not sys.stdin.read()
sys.exit(42)
