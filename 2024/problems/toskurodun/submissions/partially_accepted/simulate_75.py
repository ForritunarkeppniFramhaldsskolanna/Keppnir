#!/usr/bin/python3
n, m = map(int, input().strip().split())
ka, kb = map(int, input().strip().split())
kis = [] if m == 0 else list(map(int, input().strip().split()))
kis = [min(n, x) for x in [ka] + kis + [kb]]
bags = [i for i in range(n)]
for k in kis:
    bags = bags[::-1]
    for i in range(0, n, k):
        bags[i:i+k] = bags[i:i+k][::-1]
print(bags[0] + 1)
