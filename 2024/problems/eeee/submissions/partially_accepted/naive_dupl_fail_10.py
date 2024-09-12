#!/bin/python3
n = int(input())
sz = dict()
for _ in range(n):
    dat = input().strip().split()
    res = 0
    for k in range(2, len(dat)):
        if dat[k][0].islower():
            continue
        res += sz[dat[k]]
    sz[dat[0]] = res + 1
    print(res + 1)
