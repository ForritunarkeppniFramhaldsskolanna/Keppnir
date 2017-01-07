import sys
import re

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
n = int(n.strip())
assert 1 <= n <= 100
assert sys.stdin.read() == ''

sys.exit(42)
