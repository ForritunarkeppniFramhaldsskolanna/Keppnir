n = int(raw_input())
L = []
for i in range(n):
    x, y = map(int, raw_input().split())
    L.append(x*x+y*y)

L = sorted(L)
q = int(raw_input())
for i in range(q):
    r = int(raw_input())
    r *= r
    lo = 0
    hi = n-1
    res = 0
    while lo <= hi:
        mid = (hi+lo)//2
        if L[mid] <= r:
            res = mid+1
            lo = mid+1
        else:
            hi = mid-1
    print(res)
