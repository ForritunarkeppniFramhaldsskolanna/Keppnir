#!/usr/bin/python3
n, m = map(int, input().strip().split())
ka, kb = map(int, input().strip().split())
bags = [i for i in range(n)]
bags = bags[::-1]
for i in range(0, n, ka):
    bags[i:i+ka] = bags[i:i+ka][::-1]
bags = bags[::-1]
for i in range(0, n, kb):
    bags[i:i+kb] = bags[i:i+kb][::-1]
print(bags[0] + 1)
