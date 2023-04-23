#!/usr/bin/python3
# Solution is mostly correct but the max_votes condition fails for even values of n with a tie
from collections import defaultdict

# read input values
n, m = map(int, input().split())
candidates = []
for _ in range(m):
    candidates.append(input())

votes = []
for _ in range(n):
    vote = list(map(int, input().split()))
    votes.append(vote)

# initialize candidate rankings and vote counts
candidate_rankings = [list(range(m)) for _ in range(n)]
vote_counts = defaultdict(int)
for i in range(n):
    vote_counts[tuple(votes[i])] += 1

# perform elimination rounds until a winner is found
while True:
    # count number of first-place votes for each candidate
    first_place_votes = [0] * m
    for vote in votes:
        first_place_votes[vote[candidate_rankings[votes.index(vote)][0]] - 1] += 1

    # check if any candidate has a majority of the votes
    max_votes = max(first_place_votes)
    if max_votes > n // 2:
        winner_index = first_place_votes.index(max_votes)
        winner_name = candidates[winner_index]
        print(winner_name)
        break

    # find the candidate with the fewest first-place votes
    min_votes = min(first_place_votes)
    min_index = first_place_votes.index(min_votes)

    # eliminate the candidate with the fewest first-place votes
    for i in range(n):
        if candidate_rankings[i][0] == min_index:
            del candidate_rankings[i][0]
            vote_counts[tuple(votes[i])] -= 1
            break

    # update candidate rankings based on remaining votes
    for i in range(n):
        if tuple(votes[i]) not in vote_counts:
            continue
        while candidate_rankings[i] and tuple(votes[i])[candidate_rankings[i][0]] == min_index + 1:
            del candidate_rankings[i][0]

    # check if there are any candidates left
    if not candidate_rankings[0]:
        print("No winner")
        break

