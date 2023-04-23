#!/usr/bin/python3
n, m = map(int, input().split())

required_to_win = n//2 + 1 # simple majority

candidates = [input() for _ in range(m)]
votes = [[int(candidate_id) - 1 for candidate_id in input().split()] for _ in range(n)]

def get_results(vote_map):
    return sorted(range(len(vote_map)), key=lambda i: -len(vote_map[i]))

def has_winner(order, vote_map):
    if order is None:
        return False
    winner_id = order[0]
    winner_votes = vote_map[winner_id]
    return len(winner_votes) >= required_to_win

def get_next_loser(order, vote_map):
    for i in reversed(order):
        if len(vote_map[i]) > 0:
            return i
    assert False, "Something went wrong, no loser found, so results were empty"

def transfer_votes_from_loser(order, vote_map):
    loser_id = get_next_loser(order, vote_map)
    loser_votes = vote_map[loser_id]
    for vote in loser_votes:
        vote.pop()
        successor = vote[-1]
        while len(vote_map[successor]) == 0:
            vote.pop()
            successor = vote[-1]
        vote_map[successor].append(vote)
    loser_votes.clear()

def print_results(order, vote_map):
    for i in order:
        if len(vote_map[i]) == 0:
            break
        print("{} {} {:.2f}%".format(candidates[i], len(vote_map[i]), 100.0*len(vote_map[i])/n))

vote_map = [[] for candidate in candidates]

order = None
round_id = 1

while not has_winner(order, vote_map):
    #print("Round {}:".format(round_id))
    if order is None:
        for vote in votes:
            vote.reverse()
            first_choice = vote[-1]
            vote_map[first_choice].append(vote)
    else:
        transfer_votes_from_loser(order, vote_map)
    order = get_results(vote_map)
    #print_results(order, vote_map)
    round_id += 1

print("{}".format(candidates[order[0]]))
