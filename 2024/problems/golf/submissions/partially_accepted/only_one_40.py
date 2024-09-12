#!/usr/bin/python3

n, q = map(int, input().strip().split())
_ = input()
sm = 0
for _ in range(q):
    query = input().strip().split()
    if query[0] == "?":
        print(1, sm)
    else:
        for k in range(3, len(query), 2):
            sm += int(query[k])

