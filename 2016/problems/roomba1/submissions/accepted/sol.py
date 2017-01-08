#!/usr/bin/env python3

import os
import time

state = None
last_state = (0,0)
steps = 0
DEBUG = False

def state_print(x,y):
    global state, last_state, steps

    steps += 1
    #print(x,y)
    assert sum(map(lambda x, y: abs(x-y), last_state, (x,y))) == 1
    if DEBUG:
        state[x][y] = 'x'
        print_state()
    last_state = x,y

def print_state():
    global state
    print("\033[;H")
    print('\n'.join(map(lambda x: ''.join(x), state[::-1])))
    time.sleep(0.05)

def solve_one(size, swap):
    def sprint(a,b):
        if swap:
            a,b = b,a
        state_print(a,b)

    for i in range(1, size):
        sprint(0, i)
    for i in range(size-1):
        sprint(0, size-i-2)

def Gamma(row, col):
    for i in range(1, row):
        state_print(i, 0)
    for i in range(1,col):
        state_print(row - 1, i)

def solve_even_col(row, col):
    assert col % 2 == 0
    Gamma(row, col)
    for i in range(col-1):
        for j in range(row-1):
            if i % 2 == 0: # down
                state_print(row - j - 2, col - i - 1)
            else: # up
                state_print(j, col - i - 1)
    state_print(0,0)

def solve_even_row(row, col):
    assert row % 2 == 0
    Gamma(row, col)
    for i in range(row-1):
        for j in range(col-1):
            if i % 2 == 0: # l
                state_print(row - i - 2, col - j - 1)
            else: # up
                state_print(row - i - 2, j + 1)
    state_print(0,0)

def solve_odd_odd(row, col):
    assert row % 2 == 1 and col % 2 == 1
    Gamma(row, col)
    for i in range(col-3):
        for j in range(row-1):
            if i % 2 == 0: # down
                state_print(row - j - 2, col - i - 1)
            else: # up
                state_print(j, col - i - 1)

    for i in range(row-1):
        for j in range(2):
            if i % 2 == 0: # l
                state_print(row - i - 2, 2 - j)
            else: # up
                state_print(row - i - 2, j + 1)

    state_print(0,1)
    state_print(0,0)

def solve(row, col):
    if 1 in (row,col):
        solve_one(max(row,col), col==1)
    elif col % 2 == 0:
        solve_even_col(row, col)
    elif row % 2 == 0:
        solve_even_row(row, col)
    else: # row and col both odd
        solve_odd_odd(row, col)
    print(steps)

if __name__ == '__main__':
    row, col = map(int, input().split())
    if DEBUG:
        state = [[ '.' for _ in range(col)] for _ in range(row) ]
        os.system('clear')
    solve(row, col)

def test():
    global state, last_state, steps
    for x in range(3,4):
        for y in range(6,7):
            steps = 0
            print('dimensions:',x,y)
            row, col = x,y
            state = [[ '.' for _ in range(col)] for _ in range(row) ]
            last_state = (0,0)
            if DEBUG:
                os.system('clear')
            solve(row, col)
            input()

