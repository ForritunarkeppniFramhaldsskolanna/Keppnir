import sys
import string
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
assert(len(line) > 0)
pos = 0
sz = 0
for c in line:
    if c == 'L':
        assert(pos > 0)
        pos -= 1
    elif c == 'R':
        assert(pos < sz)
        pos += 1
    elif c == 'B':
        assert(pos > 0)
        pos -= 1
    else:
        assert(c in string.ascii_lowercase or c in string.digits)
        pos += 1
        sz += 1

notrash()
sys.exit(42)
