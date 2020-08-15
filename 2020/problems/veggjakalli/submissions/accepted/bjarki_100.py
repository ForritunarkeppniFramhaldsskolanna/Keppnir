import sys
n, m = map(int, sys.stdin.readline().split())

arr = sys.stdin.readline().strip()

r = 0
sm = 0
mn = 1000000000000000000
for l in range(1, n):
    while r-l+1 < m and r+1 < n-1:
        r += 1
        if arr[r] == '#':
            sm += 1

    if r-l+1 < m:
        break
    
    if arr[l-1] == '#' and arr[r+1] == '#':
        mn = min(mn, sm)

    if arr[l] == '#':
        sm -= 1

if mn == 1000000000000000000:
    print('Neibb')
else:
    print(mn)

