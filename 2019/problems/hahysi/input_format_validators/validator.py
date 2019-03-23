import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, m = map(int, line.split())

assert 1 <= n <= 10**18
assert 1 <= m <= 10**18

assert not sys.stdin.read()
sys.exit(42)
