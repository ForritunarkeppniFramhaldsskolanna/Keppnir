#!/usr/env/bin python3
import sys
sys.setrecursionlimit(999999999)
n, m = [int(x) for x in input().strip().split()]
pre = [int(x) - 1 for x in input().strip().split()]
_ = input()
preinv = [-1 for i in range(n)]
for i in range(n):
    preinv[pre[i]] = i
pst = [int(x) - 1 for x in input().strip().split()]
par = [-2 for i in range(n)]
def sol(prv, i1, i2):
    par[pre[i1]] = prv
    prv = pre[i1]
    while par[pst[i2]] == -2:
        i1, i2 = sol(prv, i1 + 1, i2)
    return (i1, i2 + 1)
sol(-1, 0, 0)
ch = [[] for i in range(n)]
for i in range(n):
    if par[i] >= 0:
        ch[par[i]].append(i)
for i in range(n):
    ch[i].sort(key=lambda x:preinv[x])
    print(" ".join([str(i + 1) + ":"] + [str(y + 1) for y in ch[i]]))

