#!/usr/bin/python2
n = int(raw_input())    
v = list(map(int, raw_input().split()))
nxt = [-1]*n
prv = [-1]*n
nxt_can_use = [True]*n
prv_can_use = [False]*n
for i in range(n-2, -1, -1):
    j = i+1
    flag = True
    while j != -1 and v[j] <= v[i]:
        flag &= v[i] != v[j]
        j = nxt[j]
    nxt[i] = j
    nxt_can_use[i] = flag
for i in range(1, n):
    j = i-1
    flag = True
    while j != -1 and v[j] <= v[i]:
        flag &= v[i] != v[j]
        j = prv[j]
    prv[i] = j
    prv_can_use[i] = flag
ans = 0
for i in range(n):
    if(nxt[i] != -1 and nxt_can_use[i]):
        ans = max(ans, nxt[i]-i);
    if(prv[i] != -1 and prv_can_use[i]):
        ans = max(ans, i-prv[i]);
print(ans)
