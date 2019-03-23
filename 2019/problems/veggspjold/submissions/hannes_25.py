#!/usr/bin/env python3
b, h, n = map(int, input().split())

posters = []
poster_area = 0
for i in range(n):
    x1, x2, y1, y2 = map(int, input().split())
    poster_area += (x2-x1) * (y2-y1)
    posters.append((x1, x2, y1, y2, i))


overlap_area = 0
for x1_first, x2_first, y1_first, y2_first, i_first in posters:
    for x1_second, x2_second, y1_second, y2_second, i_second in posters:
        if i_first < i_second:
            x_overlap = max(0, min(x2_first, x2_second) - max(x1_first, x1_second))
            y_overlap = max(0, min(y2_first, y2_second) - max(y1_first, y1_second))
            overlap_area += x_overlap * y_overlap

print((b*h) - poster_area + overlap_area)