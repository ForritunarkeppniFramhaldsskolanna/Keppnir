#!/usr/bin/python3

import re, sys

# bools
exec(sys.argv[1]) # joker
exec(sys.argv[2]) # high

jok = ["J"]
hic = ["O", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", "XXI"]

cards = jok + hic

for sort in ["B", "S", "V", "M"]:
    for val in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "G", "R", "D", "K"]:
        cards.append(sort + val)

jok, hic, cards = set(jok), set(hic), set(cards)

for _ in range(2):
    line = sys.stdin.readline()
    assert re.match("^[A-Z0-9]+ [A-Z0-9]+ [A-Z0-9]+ [A-Z0-9]+ [A-Z0-9]+\n$", line)
    hand = line.split()
    for card in hand:
        assert card in cards
    if not joker:
        assert card not in jok
    if not high:
        assert card not in hic

assert not sys.stdin.read()
sys.exit(42)
