#!/usr/bin/python3
mod = 10 ** 9 + 7
n = int(input())
res = 1
res *= n
res %= mod
res *= n - 1
res %= mod
res *= n - 2
res %= mod
res *= n - 3
res %= mod
res *= n - 4
res %= mod
res *= n - 5
res %= mod
res *= n - 6
res %= mod
res *= (n - 7) * (n - 8) // 2
res %= mod
res *= (n - 9) * (n - 10) // 2
res %= mod
res *= n - 11
res %= mod
res *= n - 12
res %= mod
res *= n - 13
res %= mod
res *= n - 14
res %= mod
res *= n - 15
res %= mod
res *= n - 16
res %= mod
res *= (n - 17) * (n - 18) // 2
res %= mod
res *= n - 19
res %= mod
print(res)
