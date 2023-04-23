#!/usr/bin/python3
n = int(input())
s = input().replace('D', '')
n = len(s)
best = -1
bestans = "0-0"

for i in range(n):
    wins = 0
    losses = 0
    for j in range(i, n):
        if s[j] == "G":
            wins += 1
        elif s[j] == "A":
            losses += 1
    cur = wins / max((1, wins + losses))
    if cur >= best:
        best = cur
        bestans = "{}-{}".format(wins, losses)

print(bestans)
