#!/usr/bin/python3
n, k = map(int, input().split())
A = [input() for i in range(n)]

mx = 0
if k == 3:
    dx = [-1,-1,-1,0,1,1,1,0]
    dy = [1,0,-1,-1,-1,0,1,1]
    for i in range(1,n-1):
        for j in range(1,n-1):
            if A[i][j] not in ["#", "."] and all(A[i+dy[k]][j+dx[k]] == "." for k in range(len(dx))):
                mx = max(mx, int(A[i][j]))
else:
    SUMS = [[0 for i in range(n)] for j in range(n)]

    def query(i, a, b):
        if a == 0:
            return SUMS[i][b]
        else:
            return SUMS[i][b] - SUMS[i][a-1]

    for i in range(n):
        for j in range(n):
            if j > 0:
                SUMS[i][j] = SUMS[i][j-1]
            if A[i][j] not in ["#", "."]:
                SUMS[i][j] += int(A[i][j])

    for i in range(n-k+1):
        for j in range(n-k+1):
            if (all(A[i][j+x] == '.' for x in range(k)) and
                all(A[i+k-1][j+x] == '.' for x in range(k)) and
                all(A[i+x][j] == '.' for x in range(k)) and
                all(A[i+x][j+k-1] == '.' for x in range(k))):
                mx = max(mx, sum(query(y, j+1, j+k-1) for y in range(i+1, i+k-1)))
print(mx)
