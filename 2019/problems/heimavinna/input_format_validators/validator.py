import sys
import re

def readline():
    return sys.stdin.readline().rstrip('\n')

def toint(x):
    try:
        v = int(x)
        assert(str(v) == x)
        return v
    except:
        assert(False)

line = readline()
A = []
for x in line.split(';'):
    splt = x.split('-')
    if len(splt) == 1:
        A.append(toint(splt[0]))
    elif len(splt) == 2:
        A.append(toint(splt[0]))
        A.append(toint(splt[1]))
    else:
        assert(False)

assert(A == sorted(set(A)))
assert(A[-1]-A[0] < 1000)

assert(not sys.stdin.read())
sys.exit(42)
