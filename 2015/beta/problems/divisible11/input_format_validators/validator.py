import sys
import re

n = sys.stdin.readline()
assert re.match('^[0-9]+\n$', n)
assert 1 <= int(n) <= 10**1000

assert sys.stdin.read() == ''

sys.exit(42)
