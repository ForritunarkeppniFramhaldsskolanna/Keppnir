#!/usr/bin/python3
n = 300
k, q = map(int, input().strip().split())
res = [0 for i in range(n)]

for i in range(n // 3):
    outp = [0 for j in range(n)]
    outp[3 * i] = 1
    outp[3 * i + 1] = 100
    print(*outp)
    ans = int(input())
    res[3 * i] = ans % 100
    res[3 * i + 1] = ans // 100
    outp = [0 for j in range(n)]
    outp[3 * i + 1] = 10
    outp[3 * i + 2] = 1
    print(*outp)
    ans = int(input())
    ans -= res[3 * i + 1] * 10
    ans = (ans + 1000) % 1000
    res[3 * i + 2] = ans % 100
    res[3 * i + 1] += 10 * (ans // 100)

print(*res)
