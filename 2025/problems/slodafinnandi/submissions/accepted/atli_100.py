#!/usr/bin/env python3
def mat_mul(a, b):
    c = [0 for _ in range(25)]
    for i in range(5):
        for k in range(5):
            for j in range(5):
                c[5 * i + j] += a[5 * i + k] * b[5 * k + j]
    return c


def mat_pow(a, e):
    res = [0 for _ in range(25)]
    sq = a[:]
    for i in range(5):
        res[5 * i + i] = 1
    while e > 0:
        if e & 1:
            res = mat_mul(res, sq)
        e //= 2
        if e > 0:
            sq = mat_mul(sq, sq)
    return res


BASE = [2, -1, 1, -2, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0]
RES = mat_pow(BASE, int(input()) // 5)
ans = 61 * RES[-5] + 37 * RES[-4] + 21 * RES[-3] + 9 * RES[-2] + RES[-1]
print(ans)
