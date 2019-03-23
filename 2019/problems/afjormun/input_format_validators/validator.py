import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)

assert 1 <= n <= 10**4


for i in range(n):
    line = sys.stdin.readline()
    assert len(line) <= 300
    line = line.replace(' ', '')
    # alternating case matcher, matches both aA. and Aa.
    assert re.match('^(([a-z][A-Z])*[a-z]?|([A-Z][a-z])*[A-Z]?)\.\n$', line)

assert not sys.stdin.read()
sys.exit(42)
