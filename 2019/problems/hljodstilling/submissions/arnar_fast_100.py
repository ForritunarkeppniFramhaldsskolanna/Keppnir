#!/bin/usr/python2
from itertools import combinations
import sys

L,R,k = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))

def fast(L, R, x):
    return R//x - (L-1)//x

sm = 0

for j in range(1,k+1):
    for c in combinations(A, j):
        if len(c) == 0:
            continue
        num = 1
        for x in c:
            num *= x
        sm += (-1)**(len(c)+1) * fast(L, R, num)

print(sm)
