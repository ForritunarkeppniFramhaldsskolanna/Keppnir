import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
a, b = map(int, line.split())
assert 1 <= a <= b <= 10**18

assert not sys.stdin.read()
sys.exit(42)
