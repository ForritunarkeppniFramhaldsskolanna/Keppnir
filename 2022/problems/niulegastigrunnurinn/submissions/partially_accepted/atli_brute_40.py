#!/usr/bin/python3

def cnt(n, d, g):
    res = 0
    while n > 0:
        if n % g == d:
            res += 1
        n //= g
    return res

n, d = map(int, input().strip().split())
bst = 0

for i in range(2, max(n, d) + 2):
    bst = max(bst, cnt(n, d, i))

print(bst)
