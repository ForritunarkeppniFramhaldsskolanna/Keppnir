#!/usr/bin/python3
n = 300
K, q = map(int, input().strip().split())
res = [None for _ in range(n)]
if K == 2:
    for i in range(n):
        print(*[1 if i == j else 0 for j in range(n)], flush=True)
        res[i] = int(input())
elif K == 4:
    for i in range(n // 2):
        print(*[1 if j == 2 * i else (100 if j == 2 * i + 1 else 0) for j in range(n)], flush=True)
        res[2 * i + 1], res[2 * i] = divmod(int(input()), 100)
else:
    for i in range(n // 3):
        print(*[1 if j == 3 * i else (100 if j == 3 * i + 1 else 0) for j in range(n)], flush=True)
        res[3 * i + 1], res[3 * i] = divmod(int(input()), 100)
        print(*[10 if j == 3 * i + 1 else (1 if j == 3 * i + 2 else 0) for j in range(n)], flush=True)
        ans = int(input())
        ans = (ans - res[3 * i + 1] * 10 + 1000) % 1000
        res[3 * i + 1] += 10 * (ans // 100)
        res[3 * i + 2] = ans % 100
print(*res, flush=True)
