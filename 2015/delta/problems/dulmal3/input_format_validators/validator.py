import sys
import re

s = sys.stdin.readline()
assert re.match('^[a-z]+\n$', s)
s = s.strip()
assert 1 <= len(s) <= 1000

assert sys.stdin.read() == ''
sys.exit(42)
