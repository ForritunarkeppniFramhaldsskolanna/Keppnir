import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 10**3

for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[A-Za-z]{1,100}\n$', line)

assert not sys.stdin.read()
sys.exit(42)
