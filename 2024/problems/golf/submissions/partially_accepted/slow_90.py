#!/usr/bin/python3

n, q = map(int, input().strip().split())
names = input().strip().split()
name2ind = dict()
for i in range(n):
    name2ind[names[i]] = i
scores = [0 for _ in range(n)]
for _ in range(q):
    query = input().strip().split()
    if query[0] == "?":
        ind = name2ind[query[1]]
        above = len([x for x in scores if x < scores[ind]])
        print(above + 1, scores[ind])
    else:
        for k in range(2, len(query), 2):
            ind = name2ind[query[k]]
            scores[ind] += int(query[k + 1])

