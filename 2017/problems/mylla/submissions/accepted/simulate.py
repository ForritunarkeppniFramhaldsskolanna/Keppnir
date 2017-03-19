#!/usr/bin/env python3
n = int(input())
s = input()
game = [0,0]
rounds = [0,0]
for c in s:
    if c == 'A':
        game[0] += 1
    else:
        game[1] += 1
    if max(game) == 3:
        rounds[1 if game[1] == 3 else 0] += 1
        game = [0,0]
    if max(rounds) == n:
        print('Hannes' if rounds[0] == n else 'Arnar')
        break
