#!/usr/bin/python3

n, k, p = map(int, input().strip().split())
names = list(input().strip().split())
bst = -1
for _ in range(n):
    typ, v, g = input().strip().split()
    v, g = int(v), int(g)
    if v <= p:
        bst = max(bst, g)
if bst == -1:
    print("O nei!")
else:
    print(bst)
