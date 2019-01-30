import sys
from collections import defaultdict

def readline():
    line = sys.stdin.readline().strip('\n')
    assert(line == line.strip())
    return line

def toint(s):
    i = int(s)
    assert(str(i) == s)
    return i

def tofloat(s):
    return float(s)

def inrange(lo, n, hi):
    assert(lo <= n <= hi)

def notrash():
    assert(sys.stdin.read() == '')

n = toint(readline())
for i in range(n):
    map(tofloat, readline().split())

notrash()
sys.exit(42)
