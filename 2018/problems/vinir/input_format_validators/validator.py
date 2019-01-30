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

n,q = map(toint,readline().split())
assert(1 <= n <= 10**5)
assert(1 <= q <= 10**5)

adj = set()
for i in range(q):
    line = list(map(toint, readline().split()))
    assert(line[0] in (1,2))
    if line[0] == 1:
        assert(len(line) == 3)
        assert(1 <= line[1] <= n)
        assert(1 <= line[2] <= n)
        assert(line[1] != line[2])
        assert((line[1], line[2]) not in adj)
        adj.add((line[1], line[2]))
        adj.add((line[2], line[1]))
    if line[0] == 2:
        assert(len(line) == 2)
        assert(1 <= line[1] <= n)

notrash()
sys.exit(42)
