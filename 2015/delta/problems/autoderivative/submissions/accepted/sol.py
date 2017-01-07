import sys
n = int(raw_input())

arr = map(int, raw_input().split())

for i in range(0, n):
    sys.stdout.write('%d ' % ((i+1) * arr[i+1]))

