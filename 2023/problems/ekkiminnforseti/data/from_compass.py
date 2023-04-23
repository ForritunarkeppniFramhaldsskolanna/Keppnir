#!/usr/bin/python3
import sys
import random

from collections import namedtuple
from string import ascii_uppercase

random.seed(int(sys.argv[-1]))

candidate_filename = sys.argv[1]

Person = namedtuple('Person', ['name', 'first_choice_count', 'position'])

def parse_candidate(candidate_file):
    name = candidate_file.readline().strip()
    first_choice_count = int(candidate_file.readline())
    position = tuple(map(float, candidate_file.readline().strip().split()))
    return Person(name, first_choice_count, position)

def get_random_policy_value():
    return random.uniform(-1.0, 1.0)

def get_uniform_voter(dimensions, first_choice=None):
    return [get_random_policy_value() for _ in range(dimensions)]

def get_voter_with_first_choice(dimensions, candidates, first_choice=None):
    while True:
        voter = get_uniform_voter(dimensions)
        if first_choice is None or get_vote(voter, candidates)[0] == first_choice:
            return voter

def distance_squared(a, b):
    return sum((a[i] - b[i])**2 for i in range(len(a)))

def euclidean_distance(a, b):
    return distance_squared(a, b)**0.5

def manhattan_distance(a, b):
    return sum(abs(a[i] - b[i]) for i in range(len(a)))

def max_distance(a, b):
    return max(abs(a[i] - b[i]) for i in range(len(a)))

def get_vote(voter, candidates, distance=euclidean_distance):
    vote = range(len(candidates))
    return sorted(vote, key=lambda i: distance(voter, candidates[i].position))

candidates = []
voters = []
if candidate_filename.startswith("random"):
    _, n, m, dimensions = candidate_filename.split('_')
    n = int(n)
    m = int(m)
    dimensions = int(dimensions)
    candidates = [Person(''.join(random.choice(ascii_uppercase) for j in range(10)), 0, get_uniform_voter(dimensions)) for i in range(m)]
    voters = [get_uniform_voter(dimensions) for i in range(n)]
else:
    with open(candidate_filename, "r") as candidate_file:
        m, dimensions = map(int, candidate_file.readline().split())
        candidates = [parse_candidate(candidate_file) for _ in range(m)]

    for candidate_index, candidate in enumerate(candidates):
        sys.stderr.write("Generating {} votes for {}\n".format(candidate.first_choice_count, candidate.name))
        for _ in range(candidate.first_choice_count):
            voters.append(get_voter_with_first_choice(dimensions, candidates, candidate_index))
 
votes = [get_vote(voter, candidates) for voter in voters]

n = len(votes)
print(n, m)

for candidate in candidates:
    print(candidate.name)

for vote in votes:
    print(" ".join(str(x+1) for x in vote))
