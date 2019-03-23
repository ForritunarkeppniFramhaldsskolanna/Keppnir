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
b,h,n = map(toint, line.split())

assert(1 <= b <= 10**9)
assert(1 <= h <= 10**9)
assert(1 <= n <= 10**5)

for i in range(n):
    line = readline()
    x1,x2,y1,y2 = map(toint, line.split())
    assert(0 <= x1 < x2 <= b)   
    assert(0 <= y1 < y2 <= h)   

assert(not sys.stdin.read())
sys.exit(42)
