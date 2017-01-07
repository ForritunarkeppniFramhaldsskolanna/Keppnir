import sys
import re

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
m = sys.stdin.readline()
assert re.match('^[0-9]+\n$', m)
n = int(n.strip())
m = int(m.strip())
assert 1 <= n <= 10000
assert 1 <= m <= 10000
assert n <= m

assert sys.stdin.read() == ''
sys.exit(42)
