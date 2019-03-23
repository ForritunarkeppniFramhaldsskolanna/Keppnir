#!/usr/bin/python3
k, q = map(int, input().split())
cnt = [0]*k
for i in range(q):
    a,b = map(int, input().split())
    cnt[b-1] += 1

print(min(cnt))
