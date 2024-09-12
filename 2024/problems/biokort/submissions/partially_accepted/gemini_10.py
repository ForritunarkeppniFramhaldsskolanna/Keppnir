#!/usr/bin/python3
def minimize_ticket_cost(n, m, k):
    """
    Calculates the optimal number of cinema cards and total cost for The Movie Quartet.

    Args:
        n: Number of movies this year.
        m: Price of a single-use ticket.
        k: Price of a year-long cinema card.

    Returns:
        A tuple containing the number of cards to buy and the total cost.
    """
    cost_per_use = k / 4
    num_cards = 0
    total_cost = 0

    for _ in range(n):
        movie_name, popularity = input().split()
        popularity = int(popularity)
        movie_cost = popularity * cost_per_use

        if movie_cost > m:
            num_cards += 1
            total_cost += movie_cost

    num_cards = min(num_cards, 10**6)  # Limit the number of cards
    total_cost += (n - num_cards) * m  # Cost of movies without cards

    return num_cards, total_cost


# Example usage
n, m, k = map(int, input().split())
num_cards, total_cost = minimize_ticket_cost(n, m, k)
print(num_cards, total_cost)
