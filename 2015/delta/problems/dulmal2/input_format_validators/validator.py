import sys
import re

k = sys.stdin.readline()
assert re.match('^[0-9]+\n$', k)
k = int(k.strip())
assert 1 <= k <= 1000

s = sys.stdin.readline()
assert re.match('^[a-z]+\n$', s)
s = s.strip()
assert 1 <= len(s) <= 1000

assert sys.stdin.read() == ''
sys.exit(42)
