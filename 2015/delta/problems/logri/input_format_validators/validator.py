import sys
import re

x = sys.stdin.readline()
assert re.match('^[0-9]+\.[0-9]\n$', x)
x = float(x.strip())
assert 1 < x <= 10000.0

b = sys.stdin.readline()
assert re.match('^[0-9]+\.[0-9]\n$', b)
b = float(b.strip())
assert 1.0 < b <= 1000.0

assert sys.stdin.read() == ''
sys.exit(42)
