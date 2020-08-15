import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n', line)
n,m = [int(x) for x in line.split()]
assert 1 <= n <= 5*10**5
assert 1 <= m <= n
s = sys.stdin.readline()
assert s[-1] == '\n'
s = s[:-1]
assert len(s) == n
assert set(s) <= set('#-')
assert s[0] == '#'
assert s[n-1] == '#'

assert not sys.stdin.read()
sys.exit(42)
