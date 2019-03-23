L, R, k = map(int, raw_input().split())
P = list(map(int, raw_input().split()))

ans = 0

for i in xrange(1,2**k):
    num = 1
    cnt = 1
    for j in range(k):
        if (i>>j)&1:
            cnt += 1
            num *= P[j]
    ans += (R//num-(L-1)//num)*(-1)**cnt
print(ans)
