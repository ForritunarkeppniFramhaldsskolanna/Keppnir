#!/usr/bin/env python3
b, h, n = map(int, input().split())

poster_area = 0
for i in range(n):
    x1, x2, y1, y2 = map(int, input().split())
    poster_area += (x2-x1) * (y2-y1)
print((b*h) - poster_area)