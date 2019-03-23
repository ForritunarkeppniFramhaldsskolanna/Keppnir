import sys
import re

def readline():
    return sys.stdin.readline().rstrip('\n')

def toint(x):
    try:
        v = int(x)
        assert(str(v) == x)
        return v
    except:
        assert(False)

line = readline()
n, k = map(int, line.split())

assert(1 <= n <= 100000)
assert(-10**9 <= k <= 10**9)

line = readline()
A = line.split()
for x in A:
    assert(-10**9 <= toint(x) <= 10**9)

assert(not sys.stdin.read())
sys.exit(42)
