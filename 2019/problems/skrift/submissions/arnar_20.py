#!/usr/bin/python3
import itertools
n,m,q = map(int, input().split())
A = [0]*m
B = [0]*m
sym = []
for i in range(m):
    a, b = map(int, input().split())
    A[i] = a
    sym.extend([i]*a)
    B[i] = b
Q = []
for i in range(q):
    x, y = map(int, input().split())
    Q.append((x,y))
mx = 0
for p in range(2**n):
    at = 0
    sm = 0
    if bin(p).count("1") != A[-1]:
        continue
    for x in Q:
        if x[0] == 1:
            for j in range(x[1]):
                at += 1
        else:
            for j in range(x[1]):
                at -= 1
                sm += B[-((p>>at)&1)]
    mx = max([sm,mx])
print(mx)
