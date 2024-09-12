#!/usr/bin/python3
def find_gold_stack(n):
    """
    Finds the stack containing real gold coins using the balance scale.

    Args:
        n: The number of coins in each stack.

    Returns:
        The number of the stack containing real gold coins.
    """

    # Define starting parameters
    k = n // 3  # Number of coins to take from each stack
    current_stacks = list(range(1, n + 1))  # List of all stack numbers

    while len(current_stacks) > 1:
        # Choose coins from specific stacks
        coins = [k if stack in current_stacks[:k] else 0 for stack in current_stacks]

        # Weigh the chosen coins
        weight = int(input("?" + " ".join(map(str, coins))))

        # Analyze the weight and update search space
        if weight % (n + 1) == 0:
            # Case 1: All real gold in first k stacks
            current_stacks = current_stacks[:k]
        elif weight % n == (n + 1):
            # Case 2: Real gold in last k stacks
            current_stacks = current_stacks[-k:]
        else:
            # Case 3: Check for all counterfeit or mixed with even counterfeits
            if weight == n * k:
                # All counterfeit, real gold in last n - k stacks
                current_stacks = current_stacks[-n + k :]
            else:
                # Mixed with even counterfeits, real gold in remaining stacks
                current_stacks = [
                    stack for stack in current_stacks if stack not in coins
                ]

    return current_stacks[0]


# Get the number of coins from the judge
n = int(input())

# Find the gold stack
gold_stack = find_gold_stack(n)

# Print the answer
print("!", gold_stack)
