#!/usr/bin/python3
import bisect

n = int(input())
guess2name = dict()
guess = []
for _ in range(n):
    nam, x = input().strip().split()
    x = int(x)
    guess2name[x] = nam
    guess.append(x)
guess.sort()
m = int(input())
for _ in range(m):
    x = int(input())
    if x < guess[0]:
        print(":(")
        continue
    i = bisect.bisect(guess, x)
    print(guess2name[guess[i - 1]])
