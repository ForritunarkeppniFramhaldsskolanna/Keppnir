import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

sm = 0
for i in range(n):
    sm += min(arr[i:])

print(sm)

