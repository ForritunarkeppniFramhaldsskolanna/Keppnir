#!/usr/bin/python3
import sys

def can_complete_puzzle():
    # Read the number of puzzle boxes (n) and the total number of puzzle pieces (m)
    n, m = map(int, sys.stdin.readline().split())

    # Initialize a set to keep track of all puzzle pieces we have
    puzzle_pieces = set()

    # Read each puzzle box's details
    for _ in range(n):
        box_details = list(map(int, sys.stdin.readline().split()))
        ki = box_details[0]  # The number of puzzle pieces in the current box
        pieces = box_details[1:]  # The actual puzzle pieces

        # Add each piece to the set of puzzle pieces
        puzzle_pieces.update(pieces)

    # Check if we can complete the puzzle
    if len(puzzle_pieces) == m:
        print("Jebb")  # All puzzle pieces are available
    else:
        print("Neibb")  # Some puzzle pieces are missing

# Execute the function to check if Davíð can complete the puzzle
can_complete_puzzle()

