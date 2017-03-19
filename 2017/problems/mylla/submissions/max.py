#!/usr/bin/env python3
n = input()
s = input()
wins = [0,0]
for c in s:
    if c == 'A':
        wins[0] += 1
    else:
        wins[1] += 1
print('Arnar' if wins[1] > wins[0] else 'Hannes')
