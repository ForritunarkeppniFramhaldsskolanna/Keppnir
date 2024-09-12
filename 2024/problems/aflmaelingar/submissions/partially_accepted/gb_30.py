#!/usr/bin/python3
n = 300

k, q = map(int, input().strip().split())
res = [-1 for i in range(n)]

for i in range(n // 2):
    outp = [0 for j in range(n)]
    outp[2 * i] = 1
    outp[2 * i + 1] = 100
    print(*outp)
    ans = int(input())
    res[2 * i] = ans % 100
    res[2 * i  + 1] = ans // 100

print(*res)
