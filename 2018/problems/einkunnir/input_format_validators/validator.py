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

n, s = [toint(x) for x in readline().split()]
inrange(1, n, 5*10**3)
inrange(1, s, 100)
correct = readline().split()
assert(len(x) == 1 and x.isupper() for x in correct)

for i in range(s):
    name = readline()
    assert(2 <= len(name) <= 20 and name.isalpha())
    answers = readline().split()
    assert(len(x) == 1 and x.isupper() for x in correct)


notrash()
sys.exit(42)
