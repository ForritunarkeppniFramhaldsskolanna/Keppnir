import sys
n = int(sys.stdin.readline())

cnt = 0
for i in range(n+1):
    if set(str(i)) <= set('02'):
        cnt += 1

print(cnt)

