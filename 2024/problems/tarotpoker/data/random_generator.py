#!/usr/bin/python3
import sys, random, math

random.seed(int(sys.argv[-1]))

use_high = eval(sys.argv[1])
jok = int(sys.argv[2])

hic = ["O", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", "XXI"]

cards = hic if use_high else []

for sort in ["B", "S", "V", "M"]:
    for val in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "G", "R", "D", "K"]:
        cards.append(sort + val)

for _ in range(2):
    hand = ["J" for _ in range(jok)]
    while len(hand) < 5:
        hand.append(random.choice(cards))
    random.shuffle(hand)
    print(*hand)
