import sys

n = int(sys.stdin.readline())

mx = -1
mxs = None

for i in range(n):
    s, x = sys.stdin.readline().strip().split()
    x = int(x)

    if x > mx:
        mx = x
        mxs = s

print(mxs)

