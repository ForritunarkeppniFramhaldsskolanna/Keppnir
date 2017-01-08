from __future__ import division
import sys
n,k = map(int,sys.stdin.readline().strip().split())
perm = map(int,sys.stdin.readline().strip().split())

def comp(p,q):
    return [ p[q[i]-1] for i in range(len(p)) ]

def exp(p,k):
    if k == 0:
        return list(range(1,len(p)+1))
    elif k % 2 == 1:
        return comp(p,exp(p,k-1))
    else:
        res = exp(p,k//2)
        return comp(res,res)

sys.stdout.write(' '.join(map(str, exp(perm, k))))

