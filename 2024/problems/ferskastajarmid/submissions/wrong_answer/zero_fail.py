#!/usr/bin/python3
n = int(input())
ml, nam = 0, ""
for i in range(n):
    nm, x, y = input().strip().split()
    x, y = int(x), int(y)
    if x * y > ml:
        ml = x * y
        nam = nm
print(nam)
