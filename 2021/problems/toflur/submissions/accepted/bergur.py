#!/usr/bin/env python3
n = int(input())
l = sorted(map(int, input().split()))
r = 0
for i in range(n - 1):
    r += (l[i + 1] - l[i])**2
print(r)
