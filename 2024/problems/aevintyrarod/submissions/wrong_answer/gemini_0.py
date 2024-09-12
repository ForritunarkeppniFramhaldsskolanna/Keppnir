#!/usr/bin/python3
def solve(n, x, quests):
    """
    Solves the problem of finding the order in which to complete quests to maximize experience points.

    Args:
      n: The number of quests.
      x: Jörmunrekur's initial experience points.
      quests: A list of tuples (name, a, b) representing the quests.

    Returns:
      A list of strings representing the names of the quests in the order they should be completed.
    """
    # Sort the quests by their a values in descending order, and then by their b values in descending order.
    quests.sort(key=lambda q: (-q[1], -q[2]))

    # Return the list of quest names.
    return [q[0] for q in quests]


# Read the input
n, x = map(int, input().split())
quests = []
for _ in range(n):
    name, a, b = input().split()
    quests.append((name, int(a), int(b)))

# Solve the problem and print the output
result = solve(n, x, quests)
for quest in result:
    print(quest)
