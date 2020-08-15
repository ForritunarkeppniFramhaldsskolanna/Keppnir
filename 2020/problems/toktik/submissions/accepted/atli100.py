#!/usr/env/bin python3
n = int(input())
pts = dict()
for _ in range(n):
    si, ai = input().strip().split()
    ai = int(ai)
    if si not in pts:
        pts[si] = 0
    pts[si] += ai

mx, mxn = 0, ""

for k in pts.keys():
    if pts[k] > mx:
        mxn = k
        mx = pts[k]

print(mxn)
