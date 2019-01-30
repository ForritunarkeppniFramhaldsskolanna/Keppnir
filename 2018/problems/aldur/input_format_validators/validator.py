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
inrange(1, n, 1000)
for x in range(n):
    inrange(0,toint(readline()), 10**5)
    
notrash()
sys.exit(42)
