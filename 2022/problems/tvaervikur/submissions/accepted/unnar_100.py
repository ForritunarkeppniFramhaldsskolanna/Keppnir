#!/usr/bin/python3

n, B = map(int, input().split())
L = list(map(lambda s: (int(s) + B - 1) // B, input().split()))

sm, mx = sum(L), max(L)
if sm >= 2*mx:
    print(' '.join(['1']*n))
else:
    print(' '.join(['1' if L[i] == mx else '2' for i in range(n)]))
