import sys
n = int(sys.stdin.readline().strip())
ys = map(int, sys.stdin.readline().strip().split())

def factorial(n):
    res = 1
    for i in range(2,n+1):
        res *= i
    return res

res = factorial(sum(ys))
for y in ys:
    res /= factorial(y)

print(res % 1000000007)

