#!/usr/bin/python3

n, k, p = map(int, input().strip().split())
names = list(input().strip().split())
sm, wrst = 0, 10 ** 10
for _ in range(n):
    typ, v, g = input().strip().split()
    v, g = int(v), int(g)
    wrst = min(wrst, g)
    sm += v
if sm > p or k > n:
    print("O nei!")
else:
    print(wrst)
