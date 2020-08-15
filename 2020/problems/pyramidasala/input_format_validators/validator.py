import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n,m = map(int,line.split())
assert 1 <= n <= 10**5
assert 1 <= m <= 2*n

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*( [1-9][0-9]*){%d}\n$' % (n-1), line)
assert all(1 <= x <= n for x in map(int, line.split()))

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*( [1-9][0-9]*){%d}\n$' % (m-1), line)
assert all(1 <= x <= n for x in map(int, line.split()))

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*( [1-9][0-9]*){%d}\n$' % (n-1), line)
assert all(1 <= x <= n for x in map(int, line.split()))

assert not sys.stdin.read()
sys.exit(42)
