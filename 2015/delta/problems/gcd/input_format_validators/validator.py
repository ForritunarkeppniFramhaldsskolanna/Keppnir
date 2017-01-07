import sys
import re

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
assert 1 <= int(n) <= 10
m = sys.stdin.readline().split()
assert len(m) == int(n)
for num in m:
    assert re.match("^[0-9]+$", num)
    assert 1 <= int(num) <= 100

assert sys.stdin.read() == ''
sys.exit(42)
