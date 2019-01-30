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
inrange(1, n, 10**5)
for i in range(n):
    splt = readline().split()
    assert(len(splt) == 2)
    a,b = map(toint, splt)
    inrange(-10**9, a, 10**9)
    inrange(-10**9, b, 10**9)
q = toint(readline())
inrange(1, q, 10**5)
for i in range(q):
    inrange(0, toint(readline()), 10**9)

notrash()
sys.exit(42)
