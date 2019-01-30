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
line = readline()
n = toint(line)
inrange(3, n, 3*10**5)
assert(n % 3 == 0)
line = list(map(toint, readline().split()))
assert(len(line) == n)
assert(min(line) > 0 and max(line) <= 10**9)
assert(len(line) == len(set(line)))

notrash()
sys.exit(42)
