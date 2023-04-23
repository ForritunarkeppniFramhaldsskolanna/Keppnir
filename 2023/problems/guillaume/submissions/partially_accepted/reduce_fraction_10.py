#!/usr/bin/python3
from fractions import Fraction
n = int(input())
results = input()

wins = 0
draws = 0
losses = 0

best = -1
best_output = (0,0)

for i in range(n-1, -1, -1):
    if results[i] == 'G':
        wins += 1
    elif results[i] == 'A':
        losses += 1
    else:
        draws += 1
    cur = Fraction(wins, max(wins + losses, 1))
    if cur > best:
        best = cur
        best_output = (wins, losses)

if best_output[1] != 0:
    frac = Fraction(*best_output)
    best_output = frac.numerator, frac.denominator;
print('-'.join(map(str, best_output)))
