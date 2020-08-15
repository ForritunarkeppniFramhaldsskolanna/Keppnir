import sys
n, m = map(int, sys.stdin.readline().split())

arr = [ list(map(int, sys.stdin.readline().split())) for i in range(n) ]

Q = int(sys.stdin.readline())
qs = []
for q in range(Q):
    a,b,c,d = map(int, sys.stdin.readline().split())
    a -= 1
    b -= 1
    c -= 1
    d -= 1
    qs.append((a,b,c,d, q))

lo = 0
hi = 10**18
mid = (lo+hi)//2
qs = [ (mid, lo, hi, None, qs) ]

uf = [i for i in range(n*m)]

def find(x):
    if uf[x] == x:
        return x
    uf[x] = find(uf[x])
    return uf[x]

def unite(x,y):
    uf[find(x)] = find(y)

incr = []
for i in range(n):
    for j in range(m):
        for di in range(-1, 2):
            for dj in range(-1, 2):
                if abs(di) + abs(dj) != 1:
                    continue
                ni = i + di
                nj = j + dj
                if not (0 <= ni < n and 0 <= nj < m and (arr[ni][nj], ni, nj) < (arr[i][j], i, j)):
                    continue
                incr.append((arr[i][j], i*m+j, ni*m+nj))
incr.sort()

incr2 = []
for (d, a,b) in incr:
    if find(a) != find(b):
        unite(a,b)
        incr2.append((d,a,b))
incr = incr2

done = []
while qs:
    uf = [i for i in range(n*m)]

    iat = 0
    nqs = []
    for (mid, lo, hi, res, curqs) in qs:
        while iat < len(incr) and incr[iat][0] <= mid:
            unite(incr[iat][1], incr[iat][2])
            iat += 1
        L = []
        R = []
        for (a,b,c,d, q) in curqs:
            if find(a*m+b) == find(c*m+d):
                L.append((a,b,c,d, q))
            else:
                R.append((a,b,c,d, q))

        if L:
            nlo = lo
            nhi = mid-1
            nres = mid
            nmid = (nlo+nhi)//2
            if nlo <= nhi:
                nqs.append((nmid, nlo, nhi, nres, L))
            else:
                for (a,b,c,d, q) in L:
                    done.append((q, max(nres, max(arr[a][b], arr[c][d]))))
        if R:
            nlo = mid+1
            nhi = hi
            nres = res
            nmid = (nlo+nhi)//2
            if nlo <= nhi:
                nqs.append((nmid, nlo, nhi, nres, R))
            else:
                for (a,b,c,d, q) in R:
                    done.append((q, max(nres, max(arr[a][b], arr[c][d]))))
    qs = nqs

    # qs = list(sorted(qs))
    # global change
    # change = False
    # global qat
    # qat = 0
    # # print(qs)

    # def check(done):
    #     global change
    #     global qat
    #     while qat < len(qs) and qs[qat][0] <= done:
    #         mid, lo, hi, res, a,b,c,d, q = qs[qat]
    #         if lo <= hi:
    #             change = True
    #             if find(a*m+b) == find(c*m+d):
    #                 res = mid
    #                 hi = mid-1
    #                 mid = (lo+hi)//2
    #                 qs[qat] = (mid, lo, hi, res, a,b,c,d, q)
    #             else:
    #                 lo = mid+1
    #                 mid = (lo+hi)//2
    #                 qs[qat] = (mid, lo, hi, res, a,b,c,d, q)
    #         qat += 1

    # last = 0
    # for (D,x,y) in incr:
    #     if D > last:
    #         check(last)
    #         check(D-1)
    #         last = D

    #     for dx in range(-1,2):
    #         for dy in range(-1,2):
    #             if abs(dx) + abs(dy) != 1:
    #                 continue
    #             nx = x + dx
    #             ny = y + dy
    #             if not (0 <= nx < n and 0 <= ny < m and arr[nx][ny] <= arr[x][y]):
    #                 continue
    #             unite(x*m+y, nx*m+ny)
    # check(last)
    # check(10**18)
    # if not change:
    #     break

# for (mid, lo, hi, res, a,b,c,d, q) in sorted(qs, key=lambda q: q[-1]):
#     print(max(res, max(arr[a][b], arr[c][d])))
for (q, s) in sorted(done):
    print(s)

