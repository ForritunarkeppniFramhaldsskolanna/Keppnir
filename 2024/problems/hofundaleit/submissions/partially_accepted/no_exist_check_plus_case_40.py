#!/usr/bin/python3

n, q = map(int, input().strip().split())
order = []
for _ in range(n):
    title, author = input().strip().split(', ')
    order.append((author, title))
order.sort()
to_ind = dict()
for i in range(n):
    to_ind[order[i][1]] = i + 1
outp = [-1 for _ in range(q)]
for i in range(q):
    book = input().strip()
    if book not in to_ind:
        print(*[-1 for _ in range(q)])
        exit(0)
    outp[i] = to_ind[book]
print(*outp)
