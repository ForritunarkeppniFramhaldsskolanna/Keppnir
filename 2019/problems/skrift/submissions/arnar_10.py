#!/usr/bin/python3
n,m,q = map(int, input().split())
A = [0]*m
B = [0]*m
sm = 0
for i in range(m):
    a, b = map(int, input().split())
    A[i] = a
    B[i] = b
for i in range(q):
    x, y = map(int, input().split())
    if x == 2:
        sm += B[0]*y
print(sm)
