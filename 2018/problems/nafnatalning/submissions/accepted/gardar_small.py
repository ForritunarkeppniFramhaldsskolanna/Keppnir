import sys
n,P = map(int, sys.stdin.readline().split())
if n >= 1000:
    sys.exit(0)

a = list(map(int, sys.stdin.readline().split()))
res = 0
for i in range(n):
    for j in range(i+1,n):
        res += a[i] * a[j]

print((res + P - 1) // P)
