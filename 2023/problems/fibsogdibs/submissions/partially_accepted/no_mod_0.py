#!/usr/bin/python3
MOD = 10**9 + 7

def matrix_mul(A, B, mod=MOD):
    res = [[0 for _ in range(len(B[0]))] for _ in range(len(A))]

    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(A)):
                res[i][j] += A[i][k] * B[k][j]
    
    return res

def matrix_mod_pow(A, k, mod=MOD):
    res = [[1, 0], [0, 1]]

    while k:
        if k & 1:
            res = matrix_mul(res, A)
            k -= 1
        k //= 2
        A = matrix_mul(A, A)
    
    return res

a0, a1 = map(int, input().split())
n = int(input())

A = [[1, 1], [1, 0]]

B = [[a1], [a0]]

res = matrix_mod_pow(A, 2*n)

ans = matrix_mul(res, B)

print(ans[1][0], ans[0][0])
