from random import randint
import re

def generate(movements):
    clocks = [ [12]*3 for _ in range(3) ]
    for m in movements:
        apply(m, clocks, randint(2,3))
    print( '\n'.join( ' '.join(map(str,row)) for row in clocks ) )

def apply(mov, board, times):
    for i, row in enumerate(mov):
        for j, col in enumerate(row):
            if col:
                board[i][j] = (board[i][j] + times * 3) % 12
                if board[i][j] == 0:
                    board[i][j] = 12

def create_patts(s):
    patterns = [ p.splitlines() for p in re.split('\n\n', s)]
    return [ [list(map(int,r.split())) for r in p] for p in patterns ]


