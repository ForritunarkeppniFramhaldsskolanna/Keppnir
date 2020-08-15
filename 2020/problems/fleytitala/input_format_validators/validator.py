import sys
import re

line = sys.stdin.readline()
assert re.match('^0|([1-9][0-9]*)\n$', line)
d = int(line)
assert str(d) == line.strip()
assert 0 <= d <= 10**6

line = sys.stdin.readline()
assert re.match('^0|([1-9][0-9]*)\n$', line)
k = int(line)
assert str(k) == line.strip()
assert 0 <= k <= 10**18

assert not sys.stdin.read()
sys.exit(42)
