#!/usr/bin/python3
r, c = map(int, input().strip().split())
q = int(input())
for i in range(q):
    t, x, y = map(int, input().strip().split())
    print(t + max(abs(x), abs(y)), x, y)
