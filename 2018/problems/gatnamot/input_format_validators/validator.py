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

inrange(1,toint(readline()),10**6)

notrash()
sys.exit(42)
