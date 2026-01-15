import sys

n, k = map(int, sys.stdin.readline().strip().split())
L, D = list(range(n)), list(range(n))
S, R = 0, 0
for i in range(n):
    li, di = map(int, sys.stdin.readline().strip().split())
    L[i] = li
    D[i] = di
    S += li
    R += di
T = int(sys.stdin.readline())
if S <= T:
    print(R)
    exit(0)
dp = [0 for _ in range(S + 1)]
for i in reversed(range(n)):
    cp = [0 for _ in range(S + 1)]
    for s in range(S):
        sub1 = 0 if s < k else dp[s - k]
        sub2 = 0 if s < L[i] else dp[s - L[i]] + D[i]
        cp[s] = max(sub1, sub2)
    dp = cp
print(dp[T])
