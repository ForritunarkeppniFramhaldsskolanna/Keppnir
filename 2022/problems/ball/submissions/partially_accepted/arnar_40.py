#!/bin/python3
n = int(input())
pairs = [tuple(map(int, input().split())) for i in range(n//2+1)]
for i in range(len(pairs)):
    conflict = False
    for j in range(len(pairs)):
        if i == j:
            continue
        for k in range(j+1,len(pairs)):
            if i == k:
                continue
            if (pairs[j][0] == pairs[k][0] or
                    pairs[j][1] == pairs[k][0] or
                    pairs[j][0] == pairs[k][1] or
                    pairs[j][1] == pairs[k][1]):
                conflict = True
    if conflict == False:
        print("{} {}".format(*sorted(pairs[i])))
        break
