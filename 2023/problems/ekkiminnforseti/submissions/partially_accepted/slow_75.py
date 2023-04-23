#!/usr/bin/python3
n, m = map(int, input().split())

required_to_win = n//2 + 1 # simple majority

candidates = [input() for _ in range(m)]
votes = [[int(candidate_id) - 1 for candidate_id in input().split()] for _ in range(n)]

max_rounds = m

active_candidates = list(range(m))

while len(active_candidates) > 1:
    counts = {c: 0 for c in active_candidates}
    for vote in votes:
        for x in vote:
            if x in active_candidates:
                counts[x] += 1
                break
    def swapped(key_value):
        k, v = key_value
        return v, -k
    loser = min(counts.items(), key=swapped)[0]
    active_candidates.remove(loser)

for candidate in active_candidates:
    print(candidates[candidate])
