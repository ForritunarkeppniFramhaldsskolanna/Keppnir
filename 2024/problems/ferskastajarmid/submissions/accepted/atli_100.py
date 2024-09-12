#!/usr/bin/python3
n = int(input())
mn = ("", -1)
for i in range(n):
    nam, x, y = input().strip().split()
    x, y = int(x), int(y)
    if x * y > mn[1]:
        mn = (nam, x * y)
    elif x * y == mn[1] and mn[0] > nam:
        mn = (nam, x * y)
print(mn[0])
