import sys
sys.setrecursionlimit(10**4)
n = int(sys.stdin.readline())
L = list(map(int, sys.stdin.readline().split()))

mem = [[-1 for j in range(2510)] for i in range(2510)]
def dp(at, lst):
    if at == n:
        return 0
    if mem[at][lst] != -1:
        return mem[at][lst]
    ans = dp(at+1, lst)
    if lst == n or L[at] < L[lst]:
        ans = max(ans, 1+dp(at+1, at))
    mem[at][lst] = ans
    return ans

print(dp(0, n))
