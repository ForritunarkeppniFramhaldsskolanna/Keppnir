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
inrange(0, n, 10**9)
m = toint(readline())
inrange(0, m, 2)

if m == 0:
    assert(n == 0)
if m == 1:
    assert(n > 0)
if m == 2:
    assert(n > 1)

notrash()
sys.exit(42)
