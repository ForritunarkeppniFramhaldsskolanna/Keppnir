import sys
import re

line = sys.stdin.readline()
assert re.match('^(0|[1-9][0-9]*)\n$', line)
n = int(line)
assert 1 <= n <= 10**50

assert not sys.stdin.read()
sys.exit(42)
