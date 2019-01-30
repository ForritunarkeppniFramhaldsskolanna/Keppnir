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

def inrange(lo, n, hi):
    assert(lo <= n <= hi)

def notrash():
    assert(sys.stdin.read() == '')
line = readline().split()
assert(len(line) == 2)
inrange(0, toint(line[0]), 10**15)
inrange(1, toint(line[1]), 10**4)
notrash()
sys.exit(42)
