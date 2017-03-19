#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

mx = int(sys.argv[1])
full = bool(int(sys.argv[2]))
static = bool(int(sys.argv[3]))
random.seed(int(sys.argv[4]))

n = random.randint(1,mx)

def random_round():
    wins = [0,0]
    s = ""
    for i in range(5):
        if random.random() < 0.5:
            wins[0] += 1
            s += 'A'
        else:
            wins[1] += 1
            s += 'H'
        if max(wins) == 3:
            break
    return (s, 0 if wins[0] == 3 else 1)

def random_full_round():
    wins = [0,0]
    s = ""
    for i in range(5):
        if random.random() < 0.5:
            wins[0] += 1
            s += 'A'
        else:
            wins[1] += 1
            s += 'H'
        if wins[0] == 2:
            s += 'H'*(3-i)
            wins[1] += 3-i
        elif wins[1] == 2:
            s += 'A'*(3-i)
            wins[0] += 3-i
        if max(wins) == 2:
            if random.random() < 0.5:
                wins[0] += 1
                s += 'A'
            else:
                wins[1] += 1
                s += 'H'
            break
    return (s, 0 if wins[0] == 3 else 1)

def random_game(n):
    wins = [0,0]
    s = ""
    while True:
        g, w = "", -1
        if full:
            g, w = random_full_round()
        else:
            g, w = random_round()
        s += g
        wins[w] += 1
        if max(wins) == n:
            return s, wins 

if not static:
    line, wins = random_game(n)
else:
    a, b = ('A','H') if random.random() < 0.5 else ('H', 'A')
    line = a*(3*n-3)+2*a+3*b+2*a+3*b+b*(3*n-6)

print(n)
print('%s' % line)
sys.stderr.write("S is of length {}\n".format(len(line)))
sys.stderr.write("n = {}\n".format(n)) 
sys.stderr.write("Last player to win: {}\n".format(line[-1]))
