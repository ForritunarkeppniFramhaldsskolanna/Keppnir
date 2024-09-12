#!/bin/python3
n = int(input())
refers = dict()
for _ in range(n):
    dat = input().strip().split()
    refers[dat[0]] = []
    res = 0
    for k in range(2, len(dat)):
        if dat[k][0].islower():
            continue
        refers[dat[0]].append(dat[k])
    found, q = set(), []
    q.append(dat[0])
    found.add(dat[0])
    while len(q) > 0:
        cur = q[-1]
        q.pop()
        if cur in refers:
            for neigh in refers[cur]:
                if neigh not in found:
                    found.add(neigh)
                    q.append(neigh)
    print(len(found))

