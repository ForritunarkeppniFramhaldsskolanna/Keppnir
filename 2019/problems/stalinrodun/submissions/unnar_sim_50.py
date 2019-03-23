#!/usr/bin/python3
n = int(input())
L = list(map(int, input().split()))

ans = 0
cnt = 0
used = [False]*n
while cnt != n:
    mx = 0
    for i in range(len(L)):
        if used[i]:
            continue
        if L[i] >= mx:
            used[i] = True
            cnt += 1
            mx = L[i]
    ans += 1
print(ans)
