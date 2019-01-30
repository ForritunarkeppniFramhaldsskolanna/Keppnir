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

n, L = map(toint, readline().split())
assert(1 <= n <= 1000)
assert(1 <= L <= 1000)

for i in range(n):
    l, m = map(toint, readline().split())
    assert(1 <= l <= 1000)
    assert(0 <= m <= 1000000)
    
notrash()
sys.exit(42)
