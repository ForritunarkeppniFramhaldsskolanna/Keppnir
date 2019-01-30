import sys

formulas = []
with open(sys.argv[1], 'r') as f:
    n = int(f.readline())
    A = [int(x) for x in f.readline().strip().split()]

def WA():
    sys.exit(43)

try:
    k = int(sys.stdin.readline())
    if k < -1 or k > 1000:
        WA()
    if n == 3 and (sum(A)%3!=0 or not any(A[i] == sum(A)/3 for i in range(n))):
        if k != -1:
            WA()
    else:
        ops = [tuple(map(int, sys.stdin.readline().split())) for i in range(k)]
        for a,b in ops:
            if A[b-1] > A[a-1]:
                WA()
            sm = A[a-1]+A[b-1]
            A[a-1],A[b-1] = sm/2.0,sm/2.0
        if any(A[i] != A[0] for i in range(n)):
            WA()
except Exception:
    WA() # Output was not integers

sys.exit(42)
