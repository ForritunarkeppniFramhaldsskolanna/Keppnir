import sys
import re

line = sys.stdin.readline()
assert re.match('[1-9][0-9]* [1-9][0-9]*\n', line)
n,d = [int(x) for x in line.split()]
assert 1 <= n <= 10**5
assert 1 <= d <= 10**14

line = sys.stdin.readline()
assert re.match('[1-9][0-9]*( [1-9][0-9]*)*\n', line)
t = [int(x) for x in line.split()]
assert len(t) == n
for nm in t:
    assert 1 <= nm <= 10**9

assert not sys.stdin.read()
sys.exit(42)
