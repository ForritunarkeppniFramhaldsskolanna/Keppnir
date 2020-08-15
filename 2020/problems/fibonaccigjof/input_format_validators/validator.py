import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, m = map(int, line.split())
assert 1 <= n <= 10**5
assert 1 <= m <= 10**5

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*( [1-9][0-9]*)+\n$', line)
arr = list(map(int, line.split()))
assert len(arr) == n
for x in arr:
    assert 1 <= x <= 10**9

for i in range(m):
    line = sys.stdin.readline()
    assert re.match('^(1 [1-9][0-9]* [1-9][0-9]* [1-9][0-9]*|2 [1-9][0-9]* [1-9][0-9]*)\n$', line)
    cur = list(map(int, line.split()))
    assert cur[0] in {1,2}
    if cur[0] == 1:
        op, l, r, d = cur
        assert 1 <= l <= r <= n
        assert 1 <= d <= 10**9
    else:
        op, l, r = cur
        assert 1 <= l <= r <= n

assert not sys.stdin.read()
sys.exit(42)
