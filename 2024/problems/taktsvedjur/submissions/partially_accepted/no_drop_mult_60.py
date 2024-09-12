#!/usr/bin/python3
n = int(input())
mult = 1
seq = 0
score = 0
for _ in range(n):
    x = int(input())
    if x == 0:
        seq = 0
    else:
        seq += 1
        if seq == mult * 2 and mult < 8:
            mult *= 2
            seq = 0
        score += x * mult
print(score)
