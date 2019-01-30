import sys
def readline():
    line = sys.stdin.readline().strip('\n')
    assert(line == line.strip())
    return line

def toint(x):
    res = int(x)
    assert(str(res) == x)
    return res

def inrange(lo, n, hi):
    assert(lo <= n <= hi)

def notrash():
    assert(sys.stdin.read() == '')

n,q = [toint(x) for x in readline().split()]

inrange(1,n,10**5)
inrange(1,q,10**5)

for x in xrange(q):
    arr = [toint(x) for x in readline().split()]
    if arr[0] == 1:
        assert len(arr) == 2
        inrange(1, arr[1], n)
    elif arr[0] == 2:
        assert len(arr) == 1
    elif arr[0] == 3:
        assert len(arr) == 1
    elif arr[0] == 4:
        assert len(arr) == 3
        inrange(1, arr[1], arr[2])
        inrange(arr[1], arr[2], n)
    else:
        assert 5 == 2
notrash()
sys.exit(42)
