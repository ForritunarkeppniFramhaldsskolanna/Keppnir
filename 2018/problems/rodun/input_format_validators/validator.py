import sys
from collections import defaultdict

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
n,m = map(toint, line.split())
inrange(0,n,10**5)
inrange(0,m,10**5)
names = set()
line = readline()
splt = line.split()
assert(len(splt) == n)
cnts = defaultdict(int)
for name in splt:
    names.add(name)
    cnts[name] = 0

# count incoming edges
for i in range(m):
    line = readline()
    splt = line.split()
    assert(len(splt) == 3)
    a,b,c = splt
    assert(a in names)
    assert(c in names)
    if b == '<':
        cnts[c] += 1
    elif b == '>':
        cnts[a] += 1
    else:
        assert(False)

# at least one possible starting point
for v in cnts.values():
    if v == 0:
        break
else:
    assert(False)
notrash()
sys.exit(42)
