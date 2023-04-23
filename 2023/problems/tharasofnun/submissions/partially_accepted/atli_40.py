#!/usr/bin/python3
import collections

r, c = map(int, input().strip().split())
q = int(input())
inp = [tuple(map(int, input().strip().split())) for i in range(q)]
t, x, y = 0, 0, 0
for (ti, xi, yi) in inp:
    if ti > t:
        t = ti
    steps = max(abs(x - xi), abs(y - yi))
    x, y = xi, yi
    t += steps
    print(t, x, y)

