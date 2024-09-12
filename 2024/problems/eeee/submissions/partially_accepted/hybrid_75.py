#!/bin/python3
n = int(input())
if n <= 1000:
    ind = dict()
    g = []
    outp = []
    for _ in range(n):
        dat = input().strip().split()
        if dat[0] not in ind:
            x = len(ind)
            ind[dat[0]] = x
            g.append([])
        i = ind[dat[0]]
        outp.append(i)
        for k in range(2, len(dat)):
            if dat[k][0].islower():
                continue
            if dat[k] not in ind:
                x = len(ind)
                ind[dat[k]] = x
                g.append([])
            g[i].append(ind[dat[k]])
    for i in outp:
        rch = set()
        rch.add(i)
        stk = [i]
        while len(stk) > 0:
            cur = stk[-1]
            stk.pop()
            for neigh in g[cur]:
                if neigh not in rch:
                    rch.add(neigh)
                    stk.append(neigh)
        print(len(rch))
else:
    sz = dict()
    for _ in range(n):
        dat = input().strip().split()
        res = 0
        for ref in set(dat[2:]):
            if ref[0].islower():
                continue
            res += sz[ref]
        sz[dat[0]] = res + 1
        print(res + 1)
