#!/usr/bin/python3
n = int(input())
L = list(map(int, (x for x in input().split())))

ans = 1
mx = 0
for l in L:
    if l < mx:
        ans += 1
    mx = l
print(ans)
