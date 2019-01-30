import sys
n,P = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))

res = sum(a) * sum(a) - sum(list(map(lambda x: x*x, a)))
res = res // 2

print((res + P - 1) // P)
