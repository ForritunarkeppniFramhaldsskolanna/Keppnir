#!/usr/bin/python3
n, m = map(int, input().split())
candidates = [input() for i in range(m)]
count = 0
for i in range(n):
    vote = [int(x)-1 for x in input().split()]
    if vote[0] == 0:
        count += 1

if count >= n - count:
    print(candidates[0])
else:
    print(candidates[1])
