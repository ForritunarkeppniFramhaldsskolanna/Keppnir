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
for _ in range(q):
    book = input().strip()
    if book in to_ind:
        print(to_ind[book])
    else:
        print(-1)
