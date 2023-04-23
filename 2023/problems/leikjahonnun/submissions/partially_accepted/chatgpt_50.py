#!/usr/bin/python3
from fractions import Fraction

# Read input
n = int(input())
dice = []
for i in range(n):
    sides = list(map(int, input().split()))[1:]
    dice.append(sides)

# Calculate probability distribution
probs = {0: 1}
for sides in dice:
    new_probs = {}
    for outcome, prob in probs.items():
        for roll in sides:
            new_outcome = outcome + roll
            new_prob = prob / len(sides)
            if new_outcome in new_probs:
                new_probs[new_outcome] += new_prob
            else:
                new_probs[new_outcome] = new_prob
    probs = new_probs

# Print results
for outcome in sorted(probs.keys()):
    if probs[outcome] > 0:
        frac = Fraction(probs[outcome]).limit_denominator()
        print("{} {}/{}".format(outcome, frac.numerator, frac.denominator))

