#!/usr/bin/python3

import random
from itertools import combinations
from pathlib import Path

qwerty = '~1234567890-=qwertyuiop[]asdfghjkl;\'zxcvbnm,./ '
dvorak = '~1234567890[]\',.pyfgcrl/=aoeuidhtns-;qjkxbmwvz '
bjarki = '0248613579=-/bjarkigust.,loempdcnvq;[]yzhwfx\'~ '

cases = [
    "qwerty on qwerty",
    "dvorak on dvorak",
    "bjarki on bjarki",
    "dvorak on qwerty",
    "bjarki on qwerty",
    "qwerty on dvorak",
    "bjarki on dvorak",
    "qwerty on bjarki",
    "dvorak on bjarki"
]

def write_program(filename, comb):
    with open(filename, 'w') as f:
        f.write("#!/usr/bin/python3\n")
        f.write("mappings = {}\n")
        for item in comb:
            from_layout, _, to_layout = item.split()
            from_layout = eval(from_layout)
            to_layout = eval(to_layout)
            mapping = {k: v for k, v in zip(from_layout, to_layout)}
            f.write(f"mappings[{repr(item)}] = {repr(mapping)}\n")
        f.write("case = input()\n")
        f.write("line = input()\n")
        f.write("for c in line:\n")
        f.write("    print(mappings[case][c], end='')\n")
        f.write("print()\n")


sample_groups = {cases[0], cases[4], cases[6]}

random.seed(1337)
partially_accepted = Path(__file__).absolute().parent / "partially_accepted"
for k in range(1, len(cases)):
    combs = list(combinations(cases, k))
    comb = random.choice(combs)
    score = k * 11
    if sample_groups <= set(comb):
        score += 1
    filename = partially_accepted / f"some_{k}_cases_{score}.py"
    write_program(filename, comb)
