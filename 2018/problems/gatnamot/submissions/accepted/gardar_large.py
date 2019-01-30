import sys
r = int(sys.stdin.readline())
atx = 0
aty = r
ans = 0
while atx <= r:
    while aty*aty + atx*atx > r*r:
        aty -= 1
    ans += aty
    atx += 1

ans *= 4
ans += 1

print(ans)
