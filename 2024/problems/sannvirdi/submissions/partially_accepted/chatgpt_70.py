#!/usr/bin/python3
# Read inputs from stdin and write output to stdout

def find_winners():
    n = int(input().strip())  # Number of contestants
    contestants = []
    for _ in range(n):
        name, guess = input().strip().split()
        contestants.append((name, int(guess)))
    q = int(input().strip())  # Number of ideas
    ideas = [int(input().strip()) for _ in range(q)]

    # Process each idea
    for idea in ideas:
        # Find the winning contestant for this idea
        winning_guess = -1
        winner_name = ":("
        for name, guess in contestants:
            if guess <= idea and guess > winning_guess:
                winning_guess = guess
                winner_name = name
        print(winner_name)

# Assuming the function is called to execute the solution
find_winners()
