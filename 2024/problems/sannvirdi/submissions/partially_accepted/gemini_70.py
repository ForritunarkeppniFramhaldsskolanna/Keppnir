#!/usr/bin/python3
def find_winner(contestants, correct_value):
    """Finds the winning contestant based on the correct value."""
    closest_guess = None
    winner = None

    for name, guess in contestants:
        if guess <= correct_value:  # Guess must be less than or equal to the value
            if closest_guess is None or guess > closest_guess:
                closest_guess = guess
                winner = name

    return winner if winner else ":("  # Return the winner's name or ":("


# Input section
n = int(input())
contestants = []
for _ in range(n):
    name, guess = input().split()
    contestants.append((name, int(guess)))

q = int(input())
ideas = [int(input()) for _ in range(q)]

# Output section
for idea in ideas:
    winner = find_winner(contestants, idea)
    print(winner)
