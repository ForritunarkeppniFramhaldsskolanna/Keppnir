#!/usr/bin/python3
n = int(input())
L = list(map(int, input().split()))

ans = 0
while L:
    tmp = []
    for l in L:
        tmp.append(l)
    cnt = 0
    mx = 0
    for i in range(len(tmp)):
        if tmp[i] >= mx:
            del L[i-cnt]
            cnt += 1
            mx = tmp[i]
    ans += 1
print(ans)
