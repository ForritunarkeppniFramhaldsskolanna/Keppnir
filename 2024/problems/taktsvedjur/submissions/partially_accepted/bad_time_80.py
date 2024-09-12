#!/usr/bin/python3
n = int(input())
dat = [int(input()) for _ in range(n)]
score = 0
for i in range(n):
    mult, seq = 1, 0
    for j in range(i + 1):
        if dat[j] == 0:
            if mult > 1:
                mult //= 2
            seq = 0
        else:
            seq += 1
            if seq == 2 * mult and mult < 8:
                mult *= 2
                seq = 0
    score += dat[i] * mult
print(score)
