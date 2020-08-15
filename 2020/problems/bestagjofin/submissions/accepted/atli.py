#!/usr/env/bin python3
n = int(input())
mxv, mxp = -1, ""

for i in range(n):
    p, v = input().strip().split()
    v = int(v)
    if v > mxv:
        mxv = v
        mxp = p

print(mxp)
