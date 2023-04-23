#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

min_n = eval(sys.argv[1])
max_n = eval(sys.argv[2])
min_non_draws = eval(sys.argv[3])
max_non_draws = eval(sys.argv[4])
tp = sys.argv[5]

n = random.randint(min_n, max_n)

min_non_draws = min((min_non_draws, n))
max_non_draws = min((max_non_draws, n))

def uniform_interleave(s, t):
    i = 0
    j = 0
    res = []
    while i+j < len(s)+len(t):
        s_rem = len(s) - i
        t_rem = len(t) - j
        total_rem = s_rem + t_rem
        if random.randint(1, total_rem) <= s_rem:
            res.append(s[i])
            i += 1
        else:
            res.append(t[j])
            j += 1
    return ''.join(res)

def get_uniform():
    x = random.randint(min_non_draws, max_non_draws)
    y = random.randint(0, x)
    guillaume = "G"*y
    arnar = "A"*(x-y)
    draws = "D"*(n-x)
    return uniform_interleave(draws, uniform_interleave(arnar, guillaume))

def get_streak():
    x = random.randint(min_non_draws, max_non_draws)
    y = random.randint(0, x)
    valid_games = ["G" if i < y else "A" for i in range(x)]
    draws = "D"*(n - x)
    return uniform_interleave(valid_games, draws)

d = []
if tp == "uniform":
    d = get_uniform()
elif tp == "streak":
    d = get_streak()
else:
    d = ''.join([tp[i%len(tp)] for i in range(n)])

print(len(d))
print(d)
