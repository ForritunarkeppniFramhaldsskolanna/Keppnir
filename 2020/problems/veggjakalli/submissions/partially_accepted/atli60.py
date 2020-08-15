#!/usr/env/bin python3
n, m = [int(x) for x in input().strip().split()]
ib = input().strip()
bst = 10 ** 12
for i in range(len(ib) - m - 1):
    if ib[i] != '#':
        continue
    if ib[i + m + 1] != '#':
        continue
    cnt = 0
    for j in range(i + 1, i + m + 1):
        if ib[j] == '#':
            cnt += 1
    bst = min(bst, cnt)

if bst == 10 ** 12:
    print("Neibb")
else:
    print(bst)
