#!/usr/bin/python3
dp = [0 for _ in range(5 * 10**5)]

a, b = map(int, input().split())
n = int(input())

dp[0] = a
dp[1] = b

for i in range(2, 5*10**5):
    dp[i] = (dp[i-1] + dp[i-2]) % (10**9 + 7)

print(dp[2*n], dp[2*n+1])