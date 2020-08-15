import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 2*10**6

sm = 0
for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[a-z]*\n$', line)
    x = line.strip()
    sm += len(x)

assert(n <= sm <= 2*10**6)

assert not sys.stdin.read()
sys.exit(42)
