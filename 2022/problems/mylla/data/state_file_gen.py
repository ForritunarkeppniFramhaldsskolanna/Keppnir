#!/usr/bin/python3
from itertools import permutations

def check_win(L):
    inds = ((0, 1, 2),
            (0, 3, 6),
            (0, 4, 8),
            (1, 4, 7),
            (2, 4, 6),
            (2, 5, 8),
            (3, 4, 5),
            (6, 7, 8))
    for ind_list in inds:
        first = ind_list[0]
        if L[first] != "_":
            if all(L[i] == L[first] for i in ind_list):
                return True
    return False

draws = set()
xwins = set()
owins = set()

for moves in permutations(range(9)):
    state = list("_"*9)
    for i, move in enumerate(moves):
        player = "X" if i % 2 == 0 else "O"
        state[move] = player
        if check_win(state):
            if player == "X":
                xwins.add(tuple(state))
            else:
                owins.add(tuple(state))
            break
    else:
        # DRAW
        draws.add(tuple(state))


def write_set(filename, s):
    with open(filename, 'w') as f:
        for val in s:
            f.write("{}\n".format(''.join(val)))

write_set("draws.txt", draws)
write_set("xwins.txt", xwins)
write_set("owins.txt", owins)
