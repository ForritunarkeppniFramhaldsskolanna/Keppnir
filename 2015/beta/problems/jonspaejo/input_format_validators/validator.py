import sys
import re

n = sys.stdin.readline()
assert re.match('^[?0-9]+\n$', n)
n = n.strip()
assert 1 <= len(n) <= 100
assert sys.stdin.read() == ''

sys.exit(42)
