import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
n = int(line)
assert 1 <= n <= 10**5

sm = {}
for i in range(n):
    line = sys.stdin.readline()
    assert re.match('^[a-z]{1,20} [1-9][0-9]*\n$', line)
    s, x = line.split()
    x = int(x)
    assert 1 <= x <= 10**5

    if s not in sm:
        sm[s] = 0
    sm[s] += x

mx = -1
mxcnt = 0
for k,v in sm.items():
    if v > mx:
        mx = v
        mxcnt = 0
    if v == mx:
        mxcnt += 1

assert mxcnt == 1

assert not sys.stdin.read()
sys.exit(42)

