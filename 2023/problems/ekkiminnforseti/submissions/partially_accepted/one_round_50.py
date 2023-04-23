#!/usr/bin/python3
n, m = map(int, input().split())
candidates = [input() for i in range(m)]
counts = {0: 0, 1: 0, 2: 0}
votes = []
for i in range(n):
    vote = [int(x)-1 for x in input().split()]
    votes.append(vote)
    counts[vote[0]] += 1
#print(counts)

loser = min(counts, key=lambda x: (counts[x], -x))
counts[loser] = 0

for vote in votes:
    if vote[0] == loser:
        counts[vote[1]] += 1
#print(counts)

winner = max(counts, key=lambda x: (counts[x], -x))

print(candidates[winner])
