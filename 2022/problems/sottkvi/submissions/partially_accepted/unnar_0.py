#!/usr/bin/python3

n, k, d = map(int, input().split())

sm = 0
for i in range(n):
    m = int(input())
    if m+14 < d+k:
        sm += 1
print(sm)
