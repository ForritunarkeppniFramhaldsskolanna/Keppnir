#!/usr/bin/python3
k, q = map(int, input().split())
vals = []
for i in range(q):
    a,b = map(int, input().split())
    vals.append(b)

mn = 100000000
for i in range(k):
    mn = min(mn, vals.count(i+1))

print(mn)
