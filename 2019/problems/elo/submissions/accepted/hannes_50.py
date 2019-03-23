#!/usr/bin/env python3

n, x = [int(i) for i in input().split()]

tuples = []

for i in range(n):
    l, r, a = tuple(map(int, input().split()))
    tuples.append((a, l, r))

tuples.sort()
elo = x
i = 0
while len(tuples):
    t = tuples[0]
    if t[1] <= elo and elo <= t[2]:
        elo += t[0]
    else:
        tuples = tuples[1:]
print(elo)