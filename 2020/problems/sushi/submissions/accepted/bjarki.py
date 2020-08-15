import sys
n, k = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

cnt = [ [0]*n for i in range(33) ]
for i in range(33):
    for j in range(n):
        if arr[j] == i:
            cnt[i][j] += 1
        if j > 0:
            cnt[i][j] += cnt[i][j-1]

def count(t, l, r):
    sm = cnt[t][r]
    if l > 0:
        sm -= cnt[t][l-1]
    return sm

def getk(start, t):
    lo = start
    hi = n-1
    res = None
    while lo <= hi:
        mid = (lo+hi)//2
        if count(t, start, mid) >= k:
            res = mid
            hi = mid-1
        else:
            lo = mid+1
    return res

nxt = [ [None]*n for i in range(33) ]
for i in range(33):
    for j in range(n-1, -1, -1):
        if j + 1 < n:
            nxt[i][j] = nxt[i][j+1]
        if arr[j] == i:
            nxt[i][j] = j

mem = [None]*n
def dp(at):
    if at == n:
        return 0
    if mem[at] is not None:
        return mem[at]

    jmp = []
    for i in range(1,33):
        if nxt[i][at] is not None:
            jmp.append((nxt[i][at], i))
    jmp = sorted(jmp)

    # print(at, jmp)

    mx = 0
    succ = at
    jmpat = 0
    while jmpat < len(jmp):
        add = jmp[jmpat][1]
        jmpat += 1
        ans = getk(at, add)
        if ans is None:
            break
        succ = max(succ, ans+1)
        if jmpat == len(jmp) or succ <= jmp[jmpat][0]:
            mx = max(mx, 2**jmpat + dp(succ))

    mem[at] = mx
    return mx

print(dp(0))

