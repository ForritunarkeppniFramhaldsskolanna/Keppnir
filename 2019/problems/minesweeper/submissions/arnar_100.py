#!/usr/bin/python3
n,m,k = map(int, input().split())
A = [['.' for j in range(m)] for i in range(n)]
for i in range(k):
    y, x = map(int, input().split())
    A[y-1][x-1] = '*'

for i in range(n):
    print(''.join(A[i]))
