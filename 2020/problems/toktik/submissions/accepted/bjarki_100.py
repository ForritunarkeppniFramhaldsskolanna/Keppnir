import sys

n = int(sys.stdin.readline())
sm = {}
for i in range(n):
    s, x = sys.stdin.readline().strip().split()
    x = int(x)
    if s not in sm:
        sm[s] = 0
    sm[s] += x

mx = -1
mxs = None
for k,v in sm.items():
    if v > mx:
        mx = v
        mxs = k

print(mxs)

