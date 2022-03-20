#!/usr/bin/python3

s = input()
n = len(s)
cnt, cnt2, cnt_same, last = 1, 1, 1, '0'
dec, inc, compr, rev = [-1]*n, [-1]*n, [0]*(n+3), [-1]*n
dec[0] = 1
k = 0
for i in range(n):
    if s[i] > last: cnt = 1
    if s[i] < last: cnt2 = 1
    if i != 0 and s[i] != last:
        k += 1
        cnt_same = 1
    rev[i] = k
    compr[k], dec[i], inc[i], last = cnt_same, cnt, cnt2, s[i]
    cnt_same += 1
    cnt += 1
    cnt2 += 1

ans = 0
mxDec, mxInc, mxOnes, tmpInc = 0, 0, 0, 0
i = n-1
while i >= 0:
    r = rev[i]
    if s[i] == '1':
        ans = max(ans, compr[r]+compr[r+1]+mxOnes)
        mxOnes = max(mxOnes, compr[r])
        mxInc = max(mxInc, tmpInc)
        tmpInc = inc[i]
        i -= compr[r]
        continue
    
    ans = max(ans, compr[r]+compr[r+1]+compr[r+2]+compr[r+3])
    ans = max(ans, compr[r]+mxDec)
    ans = max(ans, compr[r]+mxInc)
    if r > 1: ans = max(ans, compr[r-1] + compr[r-2] + mxOnes)

    mxDec = max(mxDec, dec[i])

    i -= compr[r]

print(ans)
