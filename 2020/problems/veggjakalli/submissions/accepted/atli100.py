#!/usr/env/bin python3
n, m = [int(x) for x in input().strip().split()]
ib = input().strip()
prf = [1 if ib[i] == '#' else 0 for i in range(len(ib))]
for i in range(1, len(prf)):
    prf[i] += prf[i - 1]
bst = 10 ** 12
for i in range(len(ib) - m - 1):
    if ib[i] != '#':
        continue
    if ib[i + m + 1] != '#':
        continue
    bst = min(bst, prf[i + m] - prf[i])

if bst == 10 ** 12:
    print("Neibb")
else:
    print(bst)
