#!/usr/bin/env python3
import sys


def print_board(board):
    for row in board:
        print("".join(row))
    sys.stdout.flush()


def get_legal_moves(board, inv_lower, inv_upper):
    moves = []
    # Type 1: Place a letter on an empty square.
    if inv_lower > 0:
        for i in range(3):
            for j in range(3):
                if board[i][j] == ".":
                    moves.append(("type1", "x", (i, j)))
    if inv_upper > 0:
        for i in range(3):
            for j in range(3):
                if board[i][j] == ".":
                    moves.append(("type1", "X", (i, j)))
    # Type 2: Play an uppercase letter from our inventory on top of a lower-case letter.
    if inv_upper > 0:
        for i in range(3):
            for j in range(3):
                if board[i][j] != "." and board[i][j].islower():
                    moves.append(("type2", "X", (i, j)))
    # Type 3: Move an uppercase letter already on board to cover some lower-case letter.
    # (We can only move our own uppercase letters.)
    for i in range(3):
        for j in range(3):
            if board[i][j] == "X":  # our uppercase letter on board
                for k in range(3):
                    for l in range(3):
                        if (k, l) != (i, j) and board[k][l] != "." and board[k][l].islower():
                            moves.append(("type3", "X", (k, l), (i, j)))
    return moves


def apply_move(board, move):
    # Return a new board after applying the move.
    # move types:
    #   'type1': placing a letter on an empty square, represented as (type, letter, (i,j))
    #   'type2': placing an uppercase letter from inventory over a lower-case letter, (type, letter, (i,j))
    #   'type3': moving an uppercase letter from src to a target lower-case cell, (type, letter, (ti,tj), (si,sj))
    new_board = [row[:] for row in board]  # deep copy of board
    if move[0] == "type1":
        letter = move[1]
        (i, j) = move[2]
        new_board[i][j] = letter
    elif move[0] == "type2":
        letter = move[1]  # 'X'
        (i, j) = move[2]
        new_board[i][j] = letter
    elif move[0] == "type3":
        letter = move[1]  # 'X'
        (ti, tj) = move[2]
        (si, sj) = move[3]
        new_board[si][sj] = "."  # remove letter from source
        new_board[ti][tj] = letter  # cover the lower-case letter
    return new_board


def main():
    inv_lower = 4  # available lower-case x's
    inv_upper = 2  # available uppercase X's

    # start with an empty board (3x3)
    board = [["." for _ in range(3)] for _ in range(3)]

    # Our first move: we choose the center square if available.
    first_move = None
    if board[1][1] == ".":
        if inv_lower > 0:
            first_move = ("type1", "x", (1, 1))
            inv_lower -= 1
        elif inv_upper > 0:
            first_move = ("type1", "X", (1, 1))
            inv_upper -= 1
    if first_move is None:
        # Otherwise choose the first empty cell we find.
        for i in range(3):
            for j in range(3):
                if board[i][j] == ".":
                    if inv_lower > 0:
                        first_move = ("type1", "x", (i, j))
                        inv_lower -= 1
                    elif inv_upper > 0:
                        first_move = ("type1", "X", (i, j))
                        inv_upper -= 1
                    if first_move is not None:
                        break
            if first_move is not None:
                break

    if first_move is None:
        return  # no legal move possible (shouldn't happen)

    board = apply_move(board, first_move)
    print_board(board)

    # Now the interactive loop: wait for judge's board, then respond.
    while True:
        # Read three lines representing the board OR a game-over message.
        lines = []
        for _ in range(3):
            line = sys.stdin.readline()
            if not line:
                return
            line = line.rstrip("\n")
            if line == "Tap!" or line == "Sigur!":
                return
            lines.append(line)
        board = [list(line) for line in lines]

        # Determine a legal move given the current board.
        legal = get_legal_moves(board, inv_lower, inv_upper)
        if not legal:
            # No legal move means we lose.
            return

        # Choose a move with a simple preference order:
        # Prefer type1 lower-case, then type1 uppercase, then type2, then type3.
        chosen_move = None
        for move in legal:
            if move[0] == "type1" and move[1] == "x":
                chosen_move = move
                break
        if chosen_move is None:
            for move in legal:
                if move[0] == "type1" and move[1] == "X":
                    chosen_move = move
                    break
        if chosen_move is None:
            for move in legal:
                if move[0] == "type2":
                    chosen_move = move
                    break
        if chosen_move is None:
            for move in legal:
                if move[0] == "type3":
                    chosen_move = move
                    break
        if chosen_move is None:
            chosen_move = legal[0]

        # Update our inventory if we are placing a piece from our supply.
        if chosen_move[0] == "type1":
            if chosen_move[1] == "x":
                inv_lower -= 1
            elif chosen_move[1] == "X":
                inv_upper -= 1
        elif chosen_move[0] == "type2":
            inv_upper -= 1
        # Type 3 moves use a piece already on the board so inventory is unchanged.

        board = apply_move(board, chosen_move)
        print_board(board)


if __name__ == "__main__":
    main()
