import sys

n, P = list(map(int, sys.stdin.readline().split(" ")))

assert(2 <= n <= 1000000)
assert(1 <= P <= 1000000000)
a = list(map(int, sys.stdin.readline().split()))
for i in range(n):
    assert(0 <= a[i] <= 1000)


sys.exit(42)
