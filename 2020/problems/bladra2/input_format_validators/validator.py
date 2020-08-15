import sys
import re

line = sys.stdin.readline()
assert re.match('^(0|-?[1-9][0-9]*) (0|-?[1-9][0-9]*) (0|[1-9][0-9]*)\n$', line)
sv,sa,st = line.split()
v,a,t = map(int, (sv,sa,st))
assert -1000 <= v <= 1000
assert -1000 <= a <= 1000
assert 0 <= t <= 1000
assert str(v) == sv
assert str(a) == sa
assert str(t) == st

assert not sys.stdin.read()
sys.exit(42)
