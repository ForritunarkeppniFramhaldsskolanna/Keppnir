#!/usr/bin/python3
n = 300

k, q = map(int, input().strip().split())
res = [-1 for i in range(n)]

print(*[0 for _ in range(n)], flush=True)
junk = int(input())

for i in range(n):
    outp = [1 if i == j else 0 for j in range(n)]
    print(*outp)
    res[i] = int(input())

print(*res)
