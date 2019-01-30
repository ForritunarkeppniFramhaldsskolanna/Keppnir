import sys
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

n = toint(readline())
inrange(1, n, 4)
[inrange(0,toint(i), 10**8) for i in readline().split()]

notrash()
sys.exit(42)
