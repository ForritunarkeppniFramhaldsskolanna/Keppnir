#!/usr/bin/python3
import sys
import random

random.seed(int(sys.argv[-1]))

ind = int(sys.argv[1])

questions = [
    "tragedy + time",  # comedy
    "repetition + repetition",  # learning
    "fire + water",  # steam
    "red + blue",  # purple
    "icelander + deadline",  # procrastination
    "throat + potato",  # danish
    "kattis + program",  # verdict
    "problem + solution",  # AC
    "contest + geometry",  # WA
    "nonsense + annoyance",  # This problem
]

print(questions[ind])
