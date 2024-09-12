#!/bin/python3
n = int(input())
sz = dict()
for _ in range(n):
    dat = input().strip().split()
    res = 0
    for ref in set(dat[2:]):
        if ref[0].islower():
            continue
        res += sz[ref]
    sz[dat[0]] = res + 1
    print(res + 1)
