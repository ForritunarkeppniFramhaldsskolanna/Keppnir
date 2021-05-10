#!/usr/bin/env python3

n = int(input())
xs = [int(x) - 1 for x in input().strip().split()]

cnt = 0
spot = -1

while True:
    corr = True
    for i in range(n):
        if xs[i] != i:
            corr = False
            break
    if corr:
        break
    cnt += 1
    if spot != -1 and xs[spot] == -1:
        xs[spot] = spot
        spot = -1
        continue
    prio = -1
    for i in range(n):
        if xs[i] != -1 and xs[xs[i]] == -1:
            prio = i
    if prio != -1:
        xs[xs[prio]] = xs[prio]
        xs[prio] = -1
        continue
    assert(spot == -1)
    for i in range(n):
        if xs[i] == i:
            continue
        spot = xs[i]
        xs[i] = -1
        break

print(cnt)
