import sys
r = int(sys.stdin.readline())

if r > 2000:
    sys.exit(0)

ans = 0
for x in range(0,r+1):
    for y in range(1,r+1):
        if x*x + y*y <= r*r:
            ans += 1

ans *= 4
ans += 1
print(ans)

