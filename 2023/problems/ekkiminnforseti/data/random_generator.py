#!/usr/bin/python3
import sys
import random

from collections import namedtuple
from string import ascii_uppercase

random.seed(int(sys.argv[-1]))

gen_type = sys.argv[1]
min_n = int(sys.argv[2])
max_n = int(sys.argv[3])
min_m = int(sys.argv[4])
max_m = int(sys.argv[5])

n = random.randint(min_n, max_n)
m = random.randint(min_m, max_m)

def random_name():
    return ''.join(random.choice(ascii_uppercase) for _ in range(10)).capitalize()

def shuffled_range(m):
    L = list(range(m))
    random.shuffle(L)
    return L

candidates = set()
while len(candidates) < m:
    candidates.add(random_name())
candidates = list(candidates)

votes = []
if gen_type == "uniform":
    votes = [shuffled_range(m) for _ in range(n)]
elif gen_type == "one_controversial":
    controversial = m-1
    for i in range(n//2 - 1):
        votes.append([m-1])
        votes[-1].extend(shuffled_range(m-1))
    while len(votes) < n:
        votes.append(shuffled_range(m-1))
        votes[-1].append(m-1)
elif gen_type == "comeback":
    for i in range(m-1):
        denom = 2**(i+1)
        for j in range(max(n//denom - 1, 0)):
            votes.append([i])
    while len(votes) < n:
        votes.append([m-1])

    for vote in votes:
        if vote[0] == m-1:
            vote.extend(shuffled_range(m-1))
        else:
            shuf = shuffled_range(m-1)
            shuf.remove(vote[0])
            vote.append(m-1)
            vote.extend(shuf)
elif gen_type == "partition":
    remaining = n
    cur = 0
    while remaining > 0:
        x = remaining if cur == m-1 else random.randint(0, remaining)
        for _ in range(x):
            shuf = list(set(range(m)) - {cur})
            random.shuffle(shuf)
            votes.append([cur] + shuf)
        remaining -= x
        cur += 1
elif gen_type == "equal":
    assert n % m == 0
    cur_vote = list(range(m))
    for i in range(m):
        for j in range(n//m):
            votes.append(list(cur_vote))
        cur_vote.insert(0, cur_vote.pop())
else:
    assert False

random.shuffle(votes)

print(n, m)

for candidate in candidates:
    print(candidate)

for vote in votes:
    print(" ".join(str(x+1) for x in vote))
