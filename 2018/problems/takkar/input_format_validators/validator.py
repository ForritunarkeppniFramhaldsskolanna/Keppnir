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
assert(0 <= toint(line) <= 10**9)
line = readline()
assert(0 <= toint(line) <= 10**9)

notrash()
sys.exit(42)
