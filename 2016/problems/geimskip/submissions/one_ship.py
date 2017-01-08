import sys

def SQ(x):
    return x*x

sys.stdin.readline()
(x,y,z,r) = map(int, sys.stdin.readline().split())

m = int(sys.stdin.readline())
found = False
for i in range(m):
    (x2,y2,z2,r2) = map(int, sys.stdin.readline().split())
    if SQ(x-x2) + SQ(y-y2) + SQ(z-z2) <= SQ(r+r2):
        found = True

if found:
    print '0'
else:
    print '1'

