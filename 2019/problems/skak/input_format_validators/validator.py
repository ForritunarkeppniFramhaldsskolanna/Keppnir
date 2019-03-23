import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
x,y = map(int, line.split())

assert 1 <= x <= 10**5
assert 1 <= y <= 10**5

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
u,v = map(int, line.split())

assert 1 <= u <= 10**5
assert 1 <= v <= 10**5

assert (x,y) != (u,v)

assert not sys.stdin.read()
sys.exit(42)
