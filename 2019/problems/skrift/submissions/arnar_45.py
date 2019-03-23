#!/usr/bin/python3
n,m,q = map(int, input().split())
A = [0]*m
B = [0]*m
sm = 0
arr = [0]*(n+1)
at = 0
for i in range(m):
    a, b = map(int, input().split())
    A[i] = a
    B[i] = b
for i in range(q):
    x, y = map(int, input().split())
    if x == 1:
        at += y
    elif x == 2:
        at -= y
        arr[at] += 1
        arr[at+y] -= 1
arr.pop()
for i in range(1,n):
    arr[i] += arr[i-1]

ind = sorted([i for i in range(m)], key=B.__getitem__, reverse=True)
at = 0
while arr:
    mx = max(arr)
    cnt = arr.count(mx)
    arr = list(filter(lambda a: a != mx, arr))
    while cnt:
        nxt = A[ind[at]]
        if nxt == 0:
            at += 1
        else:
            to_rm = min(cnt, nxt)
            sm += B[ind[at]]*to_rm*mx
            A[ind[at]] -= to_rm
            cnt -= to_rm

print(sm)
