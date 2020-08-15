#!/usr/bin/python3
n, k = map(int, input().split())
A = [input() for i in range(n)]
dx = [-1,-1,-1,0,1,1,1,0]
dy = [1,0,-1,-1,-1,0,1,1]
mx = 0
for i in range(1,n-1):
    for j in range(1,n-1):
        if A[i][j] not in ["#", "."] and all(A[i+dy[k]][j+dx[k]] == "." for k in range(len(dx))):
            mx = max(mx, int(A[i][j]))
print(mx)
