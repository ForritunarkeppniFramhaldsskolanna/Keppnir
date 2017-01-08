import sys

def SQ(x):
    return x*x

n = int(sys.stdin.readline())
shps = []
for i in range(n):
    (x,y,z,r) = map(int, sys.stdin.readline().split())
    shps.append((x,y,z,r))
ok = [True]*n

m = int(sys.stdin.readline())
for i in range(m):
    (x2,y2,z2,r2) = map(int, sys.stdin.readline().split())
    for j in range(n):
        (x,y,z,r) = shps[j]
        if SQ(x-x2) + SQ(y-y2) + SQ(z-z2) <= SQ(r+r2):
            ok[j] = False

print sum(ok)

