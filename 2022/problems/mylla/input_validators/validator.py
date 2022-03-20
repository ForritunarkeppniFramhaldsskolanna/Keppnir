#!/usr/bin/python3
import sys
import re

Ocount = 0
Xcount = 0

vis = set()
final_states = set()

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

def is_final_state(state):
    return check_win(state) or '_' not in state

def next_player(player):
    if player == 'O':
        return 'X'
    return 'O'

def dfs(state, player):
    if is_final_state(state):
        final_states.add(state)
    for i, val in enumerate(state):
        if val == '_':
            nxt = tuple(player if j == i else old for j, old in enumerate(state))
            if nxt not in vis:
                vis.add(nxt)
                dfs(nxt, next_player(player))

dfs(tuple('_' for _ in range(9)), 'X')

state = ""
for i in range(3):
    line = sys.stdin.readline()
    assert re.match('^[XO_]{3}\n$', line)
    state += line.strip()
    Ocount += line.count('O')
    Xcount += line.count('X')

state = tuple(state)

assert Xcount == Ocount or Xcount == Ocount + 1
assert state in final_states

assert not sys.stdin.read()
sys.exit(42)
